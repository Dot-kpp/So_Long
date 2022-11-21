/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dbl_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:47:46 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/18 15:38:11 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

void	free_dbl_arr(char **dbl_arr)
{
	int	i;

	i = 0;
	while (dbl_arr[i] != NULL)
	{
		free(dbl_arr[i]);
		i++;
	}
	free(dbl_arr[i]);
	free(dbl_arr);
}
