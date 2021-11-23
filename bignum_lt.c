/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_lt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:20:32 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/23 11:21:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

int		bignum_lt(t_bignum *n1, t_bignum *n2)
{
	
	return (bignum_compare(n1, n2, 1));
	// size_t	i;

	// if (n1->sign == 1 && n2->sign == 0)
	// 	return (0);
	// if ((n1->sign == 0 && n2->sign == 1) || !bignum_eq(n1, n2))
	// 	return (1);
	// if (n1->len > n2->len)
	// 	return (n1->sign == 0 ? 1 : 0);	
	// if (n1->len < n2->len)
	// 	return (n1->sign == 1 ? 1 : 0);	
	// i = 0;
	// while (i < n1->len)
	// {
	// 	if (n1->number[i] == n2->number[i])
	// 		++i;
	// 	else if (n1->number[i] > n2->number[i])
	// 		return (n1->sign == 0 ? 1 : 0);
	// 	else
	// 		return (n1->sign == 1 ? 1 : 0);
	// }
	// return (0);
}
