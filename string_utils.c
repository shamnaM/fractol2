/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmuhamm <shmuhamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:13:35 by shmuhamm          #+#    #+#             */
/*   Updated: 2024/02/07 16:50:16 by shmuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	white_space(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	return (0);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		s1++;
		s2++;
		--n;
	}
	return (*s1 - *s2);
}

double	atodbl(char *s)
{
	long	int_part;
	double	frac_part;
	double	pow;
	int		sign;

	int_part = 0;
	frac_part = 0;
	pow = 1;
	sign = +1;
	while (white_space(*s))
		s++;
	while (*s == '+' || *s == '-')
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s && *s >= '0' && *s <= '9')
		int_part = (int_part * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		pow /= 10;
		frac_part = frac_part + (*s++ - 48) * pow;
	}
	return ((int_part + frac_part) * sign);
}
