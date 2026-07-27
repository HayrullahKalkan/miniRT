#include "mini_rt.h"

void	print_vector(char *name, t_vector v)
{
	printf("%s: x=%.3f y=%.3f z=%.3f\n",
		name, v.x, v.y, v.z);
}

void	print_color(char *name, t_color c)
{
	printf("%s: R=%d G=%d B=%d\n",
		name, c.r, c.g, c.b);
}

void	print_ambient(t_ambient a)
{
	printf("\n========== AMBIENT ==========\n");
	printf("Ratio: %.3f\n", a.ratio);
	print_color("Color", a.color);
}

void	print_camera(t_camera c)
{
	printf("\n========== CAMERA ==========\n");
	print_vector("Position", c.position);
	print_vector("Orientation", c.orientation);
	printf("FOV: %.3f\n", c.fov);
}

void	print_light(t_light l)
{
	printf("\n========== LIGHT ==========\n");
	print_vector("Position", l.position);
	printf("Brightness: %.3f\n", l.brightness);
	print_color("Color", l.color);
}

void	print_spheres(t_list *list)
{
	t_sphere	*s;
	int			i;

	i = 0;
	printf("\n========== SPHERES ==========\n");
	while (list)
	{
		s = (t_sphere *)list->content;
		printf("\nSphere %d\n", i);
		print_vector("Center", s->center);
		printf("Diameter: %.3f\n", s->diameter);
		print_color("Color", s->color);
		list = list->next;
		i++;
	}
	printf("Total Sphere: %d\n", i);
}

void	print_planes(t_list *list)
{
	t_plane	*p;
	int		i;

	i = 0;
	printf("\n========== PLANES ==========\n");
	while (list)
	{
		p = (t_plane *)list->content;
		printf("\nPlane %d\n", i);
		print_vector("Point", p->point);
		print_vector("Normal", p->normal);
		print_color("Color", p->color);
		list = list->next;
		i++;
	}
	printf("Total Plane: %d\n", i);
}

void	print_cylinders(t_list *list)
{
	t_cylinder	*c;
	int			i;

	i = 0;
	printf("\n========== CYLINDERS ==========\n");
	while (list)
	{
		c = (t_cylinder *)list->content;
		printf("\nCylinder %d\n", i);
		print_vector("Center", c->center);
		print_vector("Axis", c->axis);
		printf("Diameter: %.3f\n", c->diameter);
		printf("Height: %.3f\n", c->height);
		print_color("Color", c->color);
		list = list->next;
		i++;
	}
	printf("Total Cylinder: %d\n", i);
}


void	print_scene(t_scene *scene)
{
	printf("\n\n");
	printf("################################\n");
	printf("        MINI RT SCENE DEBUG     \n");
	printf("################################\n");

	print_ambient(scene->ambient);
	print_camera(scene->camera);
	print_light(scene->light);

	print_spheres(scene->spheres);
	print_planes(scene->planes);
	print_cylinders(scene->cylinders);

	printf("\n################################\n");
	printf("          END DEBUG             \n");
	printf("################################\n\n");
}