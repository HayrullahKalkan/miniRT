/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:44:21 by hakalkan          #+#    #+#             */
/*   Updated: 2026/07/21 05:51:25 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MİNİ_RT_H
#define MİNİ_RT_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"

typedef struct  s_vector
{
	double x;
	double y;
	double z;
	
}   t_vector;

typedef struct s_color
{
	int r;
	int g;
	int b;

}	t_color;


typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*win_name;
	int		x;
	int		y;
	
}   t_mlx;
#endif