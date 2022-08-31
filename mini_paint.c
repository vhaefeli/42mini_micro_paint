/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:14:56 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/08/31 14:43:58 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

float	dist_to_center(int i, int j, float fx, float fy)
{
	float	d;

	d = (float)sqrt((i - fx) * (i - fx) + (j - fy) * (j - fy));
	return (d);
}

int	print_paint(char *drawing_table, int width, int height)
{
	int	i = 0;
	int	j = 0;

	if (!drawing_table)
		return (1);
	while (j < height)
	{
		while (i < width)
		{
			write(1, drawing_table, 1);
			i++;
			drawing_table++;
		}
		write(1, "\n", 1);
		j++;
		i = 0;
	}
	return (0);
}

int	op_error(void)
{
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

int main(int argc, char **argv)
{
	int			width;
	int			height;
	t_sq_data	sq_data;
	char		*drawing_table;
	char		background;
	int			i = 0;
	int			j = 0;
	int			k;
	float		fx;
	float		fy;
	float		fradius;
	float		d;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	sq_data.op_file = fopen(argv[1], "r");
	if (!sq_data.op_file)
		return (op_error());
	k = fscanf(sq_data.op_file,"%d %d %c\n", &width, &height, &background);
	if (width <= 0 || width > 300 || height <= 0 || height > 300)
		return (op_error());
	drawing_table = malloc(width * height * sizeof(char) + 1);
	memset(drawing_table, background, width * height);
	while (k != EOF && k > -1)
	{
		j = 0;
		k = fscanf(sq_data.op_file,"%c %f %f %f %c\n", &sq_data.sq_type, &fx, &fy, &fradius, &sq_data.c);
		if (k == -1)
			break ;
		if (fradius <= 0 || k != 5)
			return (op_error());
		if (sq_data.sq_type == 'c')
		{
			while (j < height)
			{
				while (i < width)
				{
					d = dist_to_center(i, j, fx, fy);
					if (d <= fradius)
					{
						if (dist_to_center( i - 1, j, fx, fy) > fradius || dist_to_center( i, j - 1, fx, fy) > fradius || dist_to_center(i + 1, j, fx, fy) > fradius || dist_to_center( i, j + 1, fx, fy) > fradius)
							drawing_table[j * width + i] = sq_data.c;
					}
					i++;
				}
				j++;
				i = 0;
			}
		}
		else if (sq_data.sq_type == 'C')
		{
			while (j < height)
			{
				while (i < width)
				{
					d = dist_to_center(i, j, fx, fy);
					if (d <= fradius)
						drawing_table[j * width + i] = sq_data.c;
					i++;
				}
				j++;
				i = 0;
			}
		}
		else
			return (op_error());;
	}
	print_paint(drawing_table, width, height);
	free (drawing_table);
	return (0);
}
