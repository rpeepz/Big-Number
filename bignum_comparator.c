/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_comparator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:31:38 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/20 16:58:39 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

int		bignum_eq(t_bignum* n1, t_bignum* n2)
{
	size_t	i;
	size_t	len;

	if (n1->sign == n2->sign && n1->len == n2->len)
	{
		i = 0;
		len = n1->len;
		while (i < len)
		{
			if (n1->number[i] != n2->number[i])
				break ;
			++i;
		}
		if (i == len)
			return (0);
	}
	return (1);
}

int		bignum_gt(t_bignum *n1, t_bignum *n2)
{
	size_t	i;

	if (n1->sign == 0 && n2->sign == 1)
		return (0);
	if (n1->sign == 1 && n2->sign == 0 || !bignum_eq(n1, n2))
		return (1);
	if (n1->len > n2->len)
		return (n1->sign == 0 ? 0 : 1);	
	if (n1->len < n2->len)
		return (n1->sign == 1 ? 0 : 1);	
	i = 0;
	while (i < n1->len)
	{
		if (n1->number[i] == n2->number[i])
			++i;
		else if (n1->number[i] > n2->number[i])
			return (n1->sign == 0 ? 0 : 1);
		else
			return (n1->sign == 1 ? 0 : 1);
	}
	return (0);
}

int		bignum_lt(t_bignum *n1, t_bignum *n2)
{
	size_t	i;

	if (n1->sign == 1 && n2->sign == 0)
		return (0);
	if (n1->sign == 0 && n2->sign == 1 || !bignum_eq(n1, n2))
		return (1);
	if (n1->len > n2->len)
		return (n1->sign == 0 ? 1 : 0);	
	if (n1->len < n2->len)
		return (n1->sign == 1 ? 1 : 0);	
	i = 0;
	while (i < n1->len)
	{
		if (n1->number[i] == n2->number[i])
			++i;
		else if (n1->number[i] > n2->number[i])
			return (n1->sign == 0 ? 1 : 0);
		else
			return (n1->sign == 1 ? 1 : 0);
	}
	return (0);
}