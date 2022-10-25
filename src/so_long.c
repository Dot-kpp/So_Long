#include "../include/so_long.h"


int parse_for_init(int argc, char *argv)
{
    int count;

    if (argc == 2 && argv != NULL)
    {
        count = ft_strlen(argv) - 4;
        if(ft_strncmp(&argv[count], ".ber", 4) != 0)
            input_error();
        else
            return (1);
    }
    else 
        input_error();  
    return(0);
}

void get_map_size(t_data *data, char argv[1])
{
    int i;
    int fd;
    char *rows;
    
    i = 0;
    fd = open(argv, O_RDONLY);
    rows = get_next_line(fd);
    data->h = 0;
    data->w = -1;
    while (rows[i])
    {
        i++;
        data->w++;
    }
    while (rows != NULL)
    {
        free (rows);
        rows = get_next_line(fd);
        data->h++;
    }
    data->height = data->h * 32;
    data->width = data->w * 32;
    free(rows);
    close(fd);
}


void    parse_map(t_data *data, char *argv)
{
    int i;
    int fd;

    data = get_data();
    fd = open (argv, O_RDONLY);
    data->map = ft_calloc(data->h + 1, sizeof(char *));
    i = 0;
    while (i <= data->h)
    {
        data->map[i] = get_next_line(fd);
        i++;
    }
    data->map[i] = "\0";
    close(fd);
}


void render_images(char tile, int x, int y)
{
    t_data *data;
    data = get_data();

    if (tile == '1')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
    }
    if (tile == '0')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
    }
    if (tile == 'C')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->collectable, x, y);
    }

}

void render_frame(void)
{
    int x;
    int y;
    t_data *data;

    data = get_data();
    y = 0;
    while (y < data->w)
    {
        x = 0;
        while (x < data->h)
        {
            render_images(data->map[x][y], y * 32, x * 32);
            x++;
        }
        y++;
    }
}


int main(int argc, char **argv)
{
    // int i = 0;
    t_data *data;
    data = get_data();
    if (parse_for_init(argc, argv[1]) == 1)
    {   
        init_data(*argv, argc);
        get_map_size(data, argv[1]);
        data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
        parse_map(data, argv[1]);
        // while(data->map)
        // {
        //     printf("%s", data->map[i]);
        //     i++;
        // }   
        render_frame();
        mlx_loop(data->mlx);
    }
}