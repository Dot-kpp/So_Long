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