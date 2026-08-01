/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 01:53:37 by hakalkan          #+#    #+#             */
/*   Updated: 2026/08/01 08:03:49 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void calculate_direction(int x, int y, t_ray *p_ray, t_scene *s)
{
	double new_x;
	double new_y;

	new_x = (double)x / 800;
	p_ray->direction.x = (new_x * 2) -1;
	new_y = (double)y / 800;
	p_ray->direction.y = 1 - (2 * new_y);
	p_ray->direction.z = s->camera.orientation.z;
}

void sphere_ray(t_ray ray, t_scene *s)
{
	t_list *tmp;
	
	tmp = s->spheres;
	while (tmp)
	{
		t_sphere *sp;
		sp = (t_sphere *)tmp->content;
		
		tmp = tmp->next;
	}
	
}

void render(t_scene *s)
{
	
	int x;
	int y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			t_ray p_ray;
			p_ray.origin = s->camera.position;
			calculate_direction(x,y,&p_ray,s);
			sphere_ray(p_ray,s);
			vector_normalize(p_ray.direction);
			x++;
		}
		y++;
	}
	
	
}

int main(int ac, char **av)
{
	//t_mlx a;
	t_scene scene;

	ft_bzero(&scene, sizeof(t_scene));
	(void)ac;
	(void)av;
	int fd;
	fd = open(av[1],O_RDONLY);
	if(fd < 0)
	{
		printf("Error\n");
		return (1);
	}
	parser(fd,&scene);
	print_scene(&scene);
	

	//init(&a);
	// a.mlx_ptr = mlx_init();
	// a.win_ptr= mlx_new_window(a.mlx_ptr, 800 ,800, "MİNİ_RT");
	// a.img_ptr = mlx_new_image(a.mlx_ptr ,800 ,800);
}