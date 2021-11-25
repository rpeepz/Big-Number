/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:53:09 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/25 14:53:09 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

t_bignum*			bignum_divide(t_bignum* d1, t_bignum* d2)
{
	t_bignum*	check;
	t_bignum*	tmp;

	tmp = NULL;
	check = bignum_init("0");
	if (!bignum_eq(d2, check))
		tmp = bignum_init("0");
	if (!bignum_eq(d1, check))
		tmp = bignum_init("0");
	check = bignum_increment(check);
	if (!bignum_eq(d2, check))
		tmp = bignum_init(d1->number);
	check = bignum_decrement(check);
	check = bignum_decrement(check);
	if (!bignum_eq(d2, check))
		tmp = bignum_multiply(d1, check);
	bignum_del(&check);
	if (tmp)
		return (tmp);
	else
		return (1);
}
