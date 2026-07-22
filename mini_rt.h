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


#ifndef MINI_RT_H
#define MINI_RT_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include "./getnextline/get_next_line.h"
#include "./libft/libft.h"


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

typedef struct s_ambient
{
	double		ratio;
	t_color		color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	position;
	t_vector	orientation;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	position;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_vector	center;
	double		diameter;
	t_color		color;
}	t_sphere;
typedef struct s_plane
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;

	t_list		*spheres;
	t_list		*planes;
	t_list		*cylinders;
}	t_scene;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*win_name;
	int		x;
	int		y;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_mlx;


void parser(int fd);

#endif