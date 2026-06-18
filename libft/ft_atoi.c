/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:05:33 by jgilaber          #+#    #+#             */
/*   Updated: 2026/02/16 12:05:37 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	atoi_nbr;
	int	atoi_nbr_sign;

	atoi_nbr = 0;
	atoi_nbr_sign = 1;
	while (*nptr == ' ' || (*nptr > 6 && *nptr < 14))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			atoi_nbr_sign = -atoi_nbr_sign;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		atoi_nbr = (atoi_nbr * 10) + (*nptr - '0');
		nptr++;
	}
	return (atoi_nbr_sign * atoi_nbr);
}

/*
int	main(void) {
	char str[] = "-1234ab";
	// Test1 -> -1234
	printf("%d\n", ft_atoi(str));
	char str2[] = "+1234ab";
	// Test2 -> 1234
	printf("%d\n", ft_atoi(str2));
	return (0);
}
*/