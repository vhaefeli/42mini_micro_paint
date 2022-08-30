/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:15:45 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/08/30 00:49:10 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct s_sq_data
{
	char	sq_type;
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	char	c;
} t_sq_data;

#endif