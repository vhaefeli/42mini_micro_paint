/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_pain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:14:56 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/08/30 11:09:15 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int	float_to_int_min(float min_float_nb)
{
	return ((int)min_float_nb + 1);
}

int	float_to_int_max(float max_float_nb)
{
	return ((int)max_float_nb);
}

t_sq_data	fill_sq_data(FILE *op_file)
{

}

int	print_paint(char **drawing_table, int width, int height)
{
	int	i = 0;
	int	j = 0;

	if (!drawing_table)
		return (1);
	while (j < height)
	{
		while (i < width)
		{
			write(1, drawing_table[i][j], 1);
			i++;
		}
		write(1, '\n', 1);
		j++;
		i = 0;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		width;
	int		height;
	t_sq_data	sq_data;
	char	style;
	char	**drawing_table;
	char	background;
	FILE	*op_file;
	int		i = 0;
	int		j = 0;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	op_file = fopen(argv[1], "r");
	if (!op_file)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	drawing_table = calloc(width * height, sizeof(char));
	while (j < height)
	{
		while (i < width)
		{
			drawing_table[i][j] = background;
			i++;
		}
		j++;
		i = 0;
	}
	sq_data = fill_sq_data(op_file);
	if (!sq_data)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	j = 0;
	if (sq_data.sq_type == 'r')
	{
		while (j < height)
		{
			while (i < width)
			{
				if ((i == sq_data.x_min || i == sq_data.x_max) && j >= sq_data.y_min && j <= sq_data.y_max)
					drawing_table[i][j] = sq_data.c;
				if (i >sq_data.x_min && i <sq_data.x_max && (j == sq_data.y_min || j == sq_data.y_max)
					drawing_table[i][j] = sq_data.c;
				if (i > sq_data.x_min && i < sq_data.x_max && j > sq_data.y_min && j < sq_data.y_max)
					drawing_table[i][j] = ' ';
				i++;
			}
			j++;
			i = 0;
		}
	}
	if (sq_data.sq_type == 'R')
	{
		while (j < height)
		{
			while (i < width)
			{
				if ((i >= sq_data.x_min && i <= sq_data.x_max) && j >= sq_data.y_min && j <= sq_data.y_max)
					drawing_table[i][j] = sq_data.c;
				i++;
			}
			j++;
			i = 0;
		}
	}
	return (print_paint(drawing_table, width, height));
}