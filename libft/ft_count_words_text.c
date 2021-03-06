/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:41:01 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/18 16:49:50 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words_text(char *s, char c)
{
	int j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			j++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (j);
}
