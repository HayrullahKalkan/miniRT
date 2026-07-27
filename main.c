/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 01:53:37 by hakalkan          #+#    #+#             */
/*   Updated: 2026/07/27 04:36:22 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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