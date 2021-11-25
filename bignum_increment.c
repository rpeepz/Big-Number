/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_increment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:07:00 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/25 16:07:00 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbignum.h"

t_bignum*			bignum_increment(t_bignum* n)
{
	t_bignum*	res;
	t_bignum*	tmp;
	t_bignum*	one;

	one = bignum_init("1");
	res = bignum_add(n, one);
	tmp = n;
	n = res;
	bignum_del(&one);
	bignum_del(&tmp);
	return (n);
}
