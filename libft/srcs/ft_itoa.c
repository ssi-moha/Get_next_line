/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:54:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/12 15:47:11 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_size(long n)
{
	int i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void		ft_tab(char *str, long n, int index)
{
	if (n < 10)
	{
		str[index] = n + 48;
	}
	else
	{
		str[index] = n % 10 + 48;
		ft_tab(str, n / 10, index - 1);
	}
}

char			*ft_itoa(int n)
{
	char *str;
	long nb;

	str = malloc(sizeof(char) * ft_size(n));
	nb = n;
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
		ft_tab(str, nb, ft_size(nb));
	}
	else
		ft_tab(str, nb, ft_size(nb) - 1);
	str[ft_strlen(str)] = '\0';
	return (str);
}
