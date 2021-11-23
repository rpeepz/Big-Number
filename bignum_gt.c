/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_gt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:20:10 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/23 11:22:15 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

int		bignum_gt(t_bignum *n1, t_bignum *n2)
{
	return (bignum_compare(n1, n2, 0));
	// size_t	i;

	// if (n1->sign == 0 && n2->sign == 1)
	// 	return (0);
	// if ((n1->sign == 1 && n2->sign == 0) || !bignum_eq(n1, n2))
	// 	return (1);
	// if (n1->len > n2->len)
	// 	return (n1->sign == 0 ? 0 : 1);	
	// if (n1->len < n2->len)
	// 	return (n1->sign == 1 ? 0 : 1);	
	// i = 0;
	// while (i < n1->len)
	// {
	// 	if (n1->number[i] == n2->number[i])
	// 		++i;
	// 	else if (n1->number[i] > n2->number[i])
	// 		return (n1->sign == 0 ? 0 : 1);
	// 	else
	// 		return (n1->sign == 1 ? 0 : 1);
	// }
	// return (0);
}
