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

t_bignum*	bignum_cat(t_bignum* dst, t_bignum* src)
{
	char		new_number[dst->len + src->len];
	t_bignum*	new_bignum;

	ft_bzero(new_number, dst->len + src->len);
	ft_strcat(new_number, dst->number);
	ft_strcat(new_number, src->number);
	new_bignum = bignum_init(new_number);
	bignum_swap(new_bignum, dst);
	bignum_del(&new_bignum);
	return (dst);
}

t_bignum*	do_divide(t_bignum* d1, t_bignum* d2, t_bignum* dividend, t_bignum* divisor)
{
	char		idividend[d2->len];
	char		quotient[d2->len + 1];
	t_bignum*	one;
	t_bignum*	d;
	t_bignum*	tmp2;
	t_bignum*	bignum_idividend;
	t_bignum*	bignum_remainder;
	char*		remainder;
	size_t		k;
	size_t		l;
	size_t		i;

	dividend = bignum_init(d1->number + d1->sign);
	divisor = bignum_init(d2->number + d2->sign);
	ft_bzero(quotient, divisor->len + 1);
	if (d1->sign ^ d2->sign)
		quotient[0] = '-';
	one = bignum_init("1");
	d = bignum_init("1");
	k = dividend->len;
	l = divisor->len;
// step 1: if k < l remainder is dividend and quotient is 0
	if (k < l)
		return (bignum_init("0"));
// step 2: set remainder to l-1 of msd of dividend
	remainder = (char *)malloc(sizeof(char) * (l + 1));
	ft_bzero(remainder, l);
	l -= 1;
	ft_strncat(remainder, dividend->number, l);
	bignum_remainder = bignum_init(remainder);
// step 3: inititalize i to 0
	i = 0;
	while (i < k - l)
	{
// step 4: slap on next digit from dividend (l+i) to intermediate dividend
		ft_bzero(idividend, divisor->len);
		ft_strcat(idividend, bignum_remainder->number);
		bignum_del(&bignum_remainder);
		ft_strncat(idividend, dividend->number + (l + i), 1);
		bignum_idividend = bignum_init(idividend);
// step 5: find next digit of quotient
		d = bignum_copy(d, one);
		int found = 0;
		while (!found)
		{
			tmp2 = bignum_multiply(divisor, d);
			if (!bignum_gt(tmp2, bignum_idividend))
			{
// step 6: set remainder to intermediate divident - (d * divisor)
				found = 1;
				bignum_decrement(d);
				bignum_del(&tmp2);
				tmp2 = bignum_multiply(divisor, d);
				bignum_remainder = bignum_minus(bignum_idividend, tmp2);
			}
			else
				bignum_increment(d);
			bignum_del(&tmp2);
		}
		ft_strcat(quotient, d->number);
		bignum_del(&bignum_idividend);
// step 7: if i <= (k - l) increment and go to step 4
		++i;
	}
	bignum_del(&dividend);
	bignum_del(&divisor);
	bignum_del(&d);
	bignum_del(&one);
	bignum_del(&bignum_remainder);
	free(remainder);
	return (bignum_init(quotient));
}
t_bignum*	bignum_divide(t_bignum *d1, t_bignum *d2)
{
	t_bignum *check;
	t_bignum *tmp;
	t_bignum *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	check = bignum_init("0");
	if (!bignum_eq(d2, check))
	{
		ft_putendl_fd("Error: Divide by zero", 2);
		tmp = bignum_init("0");
	}
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
	return (tmp ? tmp : do_divide(d1, d2, tmp, tmp2));
}
