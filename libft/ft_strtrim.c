/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:25 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/17 19:58:47 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s1_init_trim;
	unsigned int	s1_final_trim;

	if (!s1 || !set)
		return (NULL);
	s1_init_trim = 0;
	s1_final_trim = ft_strlen(s1);
	while (ft_strchr(set, s1[s1_init_trim]))
		s1_init_trim++;
	while (ft_strchr(set, s1[s1_final_trim - 1]) && s1_final_trim > s1_init_trim)
		s1_final_trim--;
	return (
		ft_substr(
			s1, s1_init_trim,
			(s1_final_trim - s1_init_trim)
		)
	);
}

/*
int main(void) {
    char *strtrim = malloc(sizeof(char) * 24);
    strcpy(strtrim, "abcdef123juan456abcdef\0"); //abcdef
	char *strtrim = malloc(sizeof(char) * 9);
    strcpy(strtrim, "Hello!!!");
	printf("strtrim -> %s\n", strtrim);
	printf("strtrimed -> %s\n", ft_strtrim(strtrim, "!"));
    return (0);
}

char	*ft_replace(char const *s1, char const *set)
{
	char	*replaced_str;
	size_t	replaced_str_index;
	size_t	s1_index;

	if (!s1 || !set)
		return (NULL);
	replaced_str = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!replaced_str)
		return (NULL);
	replaced_str_index = 0;
	s1_index = 0;
	while (s1[s1_index])
	{
		while (ft_strchr(set, s1[s1_index]))
			s1_index++;
		replaced_str[replaced_str_index] = s1[s1_index];
		replaced_str_index++;
		s1_index++;
	}
	replaced_str[replaced_str_index] = '\0';
	return (replaced_str);
}*/