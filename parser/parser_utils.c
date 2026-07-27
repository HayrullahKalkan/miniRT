/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:05:39 by hakalkan          #+#    #+#             */
/*   Updated: 2026/07/27 04:06:15 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_color parse_color(char *s)
{
    t_color color;
    char **rgb;

    rgb = ft_split(s,',');
    color.r = ft_atoi(rgb[0]);
    color.g = ft_atoi(rgb[1]);
    color.b = ft_atoi(rgb[2]);

    return color;
}
t_vector parse_vector(char *s)
{
    char **vector;
    t_vector xyz;
    
    vector = ft_split(s, ',');
    xyz.x = ft_atod(vector[0]);
    xyz.y = ft_atod(vector[1]);
    xyz.z = ft_atod(vector[2]);

    return xyz;
}   

void parser_ambient(char **split , t_scene *s)
{
    s->ambient.ratio = ft_atod(split[1]);
    s->ambient.color = parse_color(split[2]);
}

void parser_camera(char **arg, t_scene *s)
{
    s->camera.position = parse_vector(arg[1]);
    s->camera.orientation = parse_vector(arg[2]);
    s->camera.fov = ft_atod(arg[3]);
}

void parser_light(char **arg,t_scene *s)
{

    s->light.position = parse_vector(arg[1]);
    s->light.color =  parse_color(arg[3]);
    s->light.brightness = ft_atod(arg[2]);

}