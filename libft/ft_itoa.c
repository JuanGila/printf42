/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:33:51 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:33:51 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_get_itoa_number_length(int n)
{
	size_t	nbr_digits;

	if (!n)
		return (0);
	nbr_digits = 0;
	while (n != 0)
	{
		n /= 10;
		nbr_digits++;
	}
	return (nbr_digits);
}

void ft_do_itoa_positive(long nbr, size_t nbr_len, char *itoa_nbr)
{
	itoa_nbr[nbr_len + 1] = '\0';
	while (nbr_len > 0)
	{
		itoa_nbr[--nbr_len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
}

void ft_do_itoa_negative(long nbr, size_t nbr_len, char *itoa_nbr)
{
	itoa_nbr[0] = '-';
	itoa_nbr[nbr_len + 1] = '\0';
	while (nbr_len > 1)
	{
		itoa_nbr[--nbr_len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	nbr_len;
	char	*itoa_nbr;
	int		itoa_nbr_sign;

	if (!n)
		return (ft_strdup("0"));
	nbr = n;
	nbr_len = ft_get_itoa_number_length(nbr);
	itoa_nbr_sign = 0;
	if (nbr < 0)
	{
		itoa_nbr_sign = 1;
		nbr = -nbr;
		nbr_len++;
	}
	itoa_nbr = malloc(sizeof(char) * nbr_len + 1);
	if (!itoa_nbr)
		return (NULL);
	if (itoa_nbr_sign)
		ft_do_itoa_negative(nbr, nbr_len, itoa_nbr);
	else
		ft_do_itoa_positive(nbr, nbr_len, itoa_nbr);
	return (itoa_nbr);
}
/*
int main() {
    int n = 12345;
    printf("ft_itoa -> %s\n", ft_itoa(n));
    return (0);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	nbr_len;
	char	*itoa_nbr;
	int		itoa_nbr_sign;

	if (!n)
		return (ft_strdup("0"));
	nbr = n;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr_len = ft_get_itoa_number_length(nbr);
	itoa_nbr_sign = 0;
	if (nbr < 0)
	{
		itoa_nbr_sign = 1;
		nbr = -nbr;
		nbr_len++;
	}
	itoa_nbr = malloc(sizeof(char) * nbr_len + 1);
	if (!itoa_nbr)
		return (NULL);
	itoa_nbr[nbr_len + 1] = '\0';
	if (itoa_nbr_sign)
		itoa_nbr[0] = '-';
	if (itoa_nbr_sign)
	{
		while (nbr_len > 1)
		{
			itoa_nbr[--nbr_len] = (nbr % 10) + '0';
			nbr = nbr / 10;
		}
	}
	else
	{
		while (nbr_len > 0)
		{
			itoa_nbr[--nbr_len] = (nbr % 10) + '0';
			nbr = nbr / 10;
		}
	}
	return (itoa_nbr);
}
*/