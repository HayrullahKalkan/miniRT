/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:24:08 by hakalkan          #+#    #+#             */
/*   Updated: 2026/07/26 23:24:08 by hakalkan         ###   ########.fr       */
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

void parser_sphere(char **arg , t_scene *s)
{
    t_sphere *sphere;

    sphere = malloc(sizeof(t_sphere));
    sphere->center = parse_vector(arg[1]);
    sphere->diameter = ft_atod(arg[2]);
    sphere->color = parse_color(arg[3]);

    ft_lstadd_back(&s->spheres, ft_lstnew(sphere));
}
void parser_planes(char **arg , t_scene *s)
{
    t_plane *pl;

    pl = malloc(sizeof(t_plane));
    pl->point = parse_vector(arg[1]);
    pl->normal = parse_vector(arg[2]);
    pl->color = parse_color(arg[3]);
    
    ft_lstadd_back(&s->planes, ft_lstnew(pl));
}

void parser_cy(char **arg, t_scene *s)
{
    t_cylinder *cy;

    cy = malloc(sizeof(t_cylinder));
    cy->center = parse_vector(arg[1]);
    cy->axis = parse_vector(arg[2]);
    cy->color = parse_color(arg[5]);
    cy->diameter = ft_atod(arg[3]);
    cy->height = ft_atod(arg[4]);

    ft_lstadd_back(&s->cylinders, ft_lstnew(cy));
}

void parse_line(char *line, t_scene *s)
{
    int i;
    char **split;
    
    i = 0;
    split = ft_split(line , ' ');
    if (!ft_strncmp(split[0], "A", 2))
        parser_ambient(split, s);
    else if (!ft_strncmp(split[0], "C",2))
        parser_camera(split, s);
    else if (!ft_strncmp(split[0], "L", 2))
        parser_light(split,s);
    else if (!ft_strncmp(split[0],"sp", 3))
        parser_sphere(split,s);
    else if (!ft_strncmp(split[0],"pl", 3))
        parser_planes(split,s);
    else if (!ft_strncmp(split[0],"cy", 3))
        parser_cy(split, s);
}


void parser(int fd,t_scene *s)
{
    char *line;
    while((line = get_next_line(fd)) != NULL)
    {
        parse_line(line,s);
        free(line);
    }
}