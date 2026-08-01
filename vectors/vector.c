/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:31:39 by hakalkan          #+#    #+#             */
/*   Updated: 2026/08/01 07:50:16 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vector vector_add(t_vector *x1 ,t_vector *x2)
{
	t_vector sum;
	
	sum.x = x1->x + x2->x;
	sum.y = x1->y + x2->y;
	sum.z = x1->z + x2->z;

	return (sum);
}

t_vector *vector_sub(t_vector *x1 ,t_vector *x2)
{
	t_vector *sum;
	sum = malloc(sizeof(t_vector));
	
	sum->x = x1->x - x2->x;
	sum->y = x1->y - x2->y;
	sum->z = x1->z - x2->z;

	return (sum);
}
t_vector vector_scale(t_vector *vec ,double fold)
{
	t_vector res;
	
	res.x = vec->x * fold;
	res.y = vec->y * fold;
	res.z = vec->z * fold;
	
	return (res);
}

double vector_lenght(t_vector *x)
{
	double sum;	

	sum = (x->x*x->x) + (x->y*x->y) + (x->z*x->z);
	sum = sqrt(sum);
	return (sum);
}
t_vector *vector_normalize(t_vector *vec)
{
	double len;

	len = vector_lenght(vec);
	if (len == 0)
		return (vec);
	
	vec->x = vec->x/len;
	vec->y = vec->y/len;
	vec->z = vec->z/len;
	
	return (vec);
}

double vector_dot(t_vector *v1, t_vector *v2)
{
	double sum;

	sum = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	
	return (sum);
}

t_vector *vector_cross(t_vector *v1, t_vector *v2)
{
	t_vector *v_cros;
	
	v_cros = malloc(sizeof(t_vector));
	v_cros->x = v1->y * v2->z - v1->z * v2->y;
	v_cros->y = v1->z * v2->x - v1->x * v2->z;
	v_cros->z = v1->x * v2->y - v1->y * v2->x;
	
	return(v_cros);
}