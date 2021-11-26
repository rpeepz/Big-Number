/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:53:09 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/26 15:53:09 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libbignum.h"

t_bignum*			init_remainder(char* dividend, size_t size)
{
	t_bignum*	bignum_remainder;
	char*		remainder;

	remainder = (char *)malloc(sizeof(char) * (size + 1));
	ft_bzero(remainder, size);
	size -= 1;
	ft_strncat(remainder, dividend, size);
	bignum_remainder = bignum_init(remainder);
	free(remainder);
	return (bignum_remainder);
}

t_bignum			*find_quotient(t_bignum* divisor, t_bignum* bignum_id,\
									t_bignum* remainder, char *quotient)
{
	t_bignum*	tmp;
	t_bignum*	d;
	int			found;

	d = bignum_init("1");
	found = 0;
	while (!found)
	{
		tmp = bignum_multiply(divisor, d);
		if (!bignum_gt(tmp, bignum_id))
		{
			found = 1;
			bignum_decrement(d);
			bignum_del(&tmp);
			tmp = bignum_multiply(divisor, d);
			remainder = bignum_minus(bignum_id, tmp);
		}
		else
			bignum_increment(d);
		bignum_del(&tmp);
	}
	ft_strcat(quotient, d->number);
	bignum_del(&d);
	return (remainder);
}

t_bignum*			get_quotient(t_bignum* dividend, t_bignum* divisor,\
									t_bignum* remainder, char* quotient)
{
	size_t		k;
	size_t		l;
	size_t		i;
	char		idividend[divisor->len];
	t_bignum*	bignum_idividend;

	k = dividend->len;
	l = divisor->len - 1;
	i = 0;
	while (i < k - l)
	{
		ft_bzero(idividend, divisor->len);
		ft_strcat(idividend, remainder->number);
		bignum_del(&remainder);
		ft_strncat(idividend, dividend->number + (l + i), 1);
		bignum_idividend = bignum_init(idividend);
		remainder = find_quotient(divisor, bignum_idividend, remainder, quotient);
		bignum_del(&bignum_idividend);
		++i;
	}
	return (remainder);
}

t_bignum*			do_divide(t_bignum* d1, t_bignum* d2,\
					t_bignum* dividend, t_bignum* divisor)
{
	char		*quotient;
	t_bignum*	remainder;
	t_bignum*	bignum_quotient;

	dividend = bignum_init(d1->number + d1->sign);
	divisor = bignum_init(d2->number + d2->sign);
	if (dividend->len < divisor->len)
		return (bignum_init("0"));
	remainder = init_remainder(dividend->number, divisor->len);
	quotient = (char*)malloc(sizeof(char) * (d2->len + 2));
	ft_bzero(quotient, d2->len + 1);
	if (d1->sign ^ d2->sign)
		quotient[0] = '-';
	remainder = get_quotient(dividend, divisor, remainder, quotient);
	bignum_del(&remainder);
	bignum_quotient = bignum_init(quotient);
	free(quotient);
	bignum_del(&dividend);
	bignum_del(&divisor);
	return (bignum_quotient);
}

t_bignum*			bignum_divide(t_bignum *d1, t_bignum *d2)
{
	t_bignum *check;
	t_bignum *n1;
	t_bignum *n2;

	n1 = NULL;
	n2 = NULL;
	check = bignum_init("0");
	if (!bignum_eq(d2, check))
	{
		ft_putendl_fd("Error: Divide by zero", 2);
		n1 = bignum_init("0");
	}
	if (!bignum_eq(d1, check))
		n1 = bignum_init("0");
	check = bignum_increment(check);
	if (!bignum_eq(d2, check))
		n1 = bignum_init(d1->number);
	check = bignum_decrement(check);
	check = bignum_decrement(check);
	if (!bignum_eq(d2, check))
		n1 = bignum_multiply(d1, check);
	bignum_del(&check);
	return (n1 ? n1 : do_divide(d1, d2, n1, n2));
}
