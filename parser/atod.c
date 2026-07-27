/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:24:05 by hakalkan          #+#    #+#             */
/*   Updated: 2026/07/26 23:24:16 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



static double	ft_atod_decimal(char *str, int i, double *div)
{
	double	frac_part;

	frac_part = 0.0;
	*div = 1.0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		frac_part = frac_part * 10.0 + (str[i] - '0');
		*div *= 10.0;
		i++;
	}
	return (frac_part);
}

double	ft_atod(char *str)
{
	int		i;
	double	sign;
	double	count;
	double	frac_part;
	double	div;

	i = 0;
	sign = 1.0;
	count = 0.0;
	frac_part = 0.0;
	div = 1.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (str[i] && str[i] != '.')
		count = count * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	frac_part = ft_atod_decimal(str, i, &div);
	return ((count + frac_part / div) * sign);
}
