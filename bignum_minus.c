/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:53:16 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/23 10:54:20 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

static t_bignum*	do_work(t_bignum* n1, t_bignum *n2, size_t k, int type)
{
	size_t		i;
	size_t		j;
	char*		result;
	t_bignum*	num;

	result = (char*)malloc(sizeof(char) * (k + 1));
	init_result(result, k, (int)n1->sign);
	i = n1->len;
	j = n2->len;
	while (!(i == 0 && j == 0))
	{
		--k;
		if (type)
		{
			result[k] += do_dif(&i, &j, n1->number, n2->number);
			if (k && result[k] < '0')
			{
				result[k] += 10;
				result[k - 1] -= 1;
			}
		}
		else
		{
			result[k] += do_sum(&i, &j, n1->number, n2->number);
			if (k && result[k] > '9')
			{
				result[k] -= 10;
				result[k - 1] += 1;
			}
		}
	}
	num = bignum_init(result);
	free(result);
	return (num);
}

static int			check_sign(t_bignum* n1, t_bignum* n2, int type)
{
	if (n1->sign)
	{
		n1->sign = 0;
		n1->number = (n1->number) + 1;
		n1->len -= 1;
		if (type && !bignum_eq(n1, n2))
		{
			n1->sign = 1;
			n1->number = (n1->number) - 1;
			n1->len += 1;
			return (-1);
		}
		if (type && bignum_gt(n1, n2))
		{
			n1->sign = 1;
			n1->number = (n1->number) - 1;
			n1->len += 1;
			bignum_swap(n1, n2);
			return (1);
		}
		else
		{
			n1->sign = 1;
			n1->number = (n1->number) - 1;
			n1->len += 1;
		}
	}
	else if (n2->sign)
	{
		n2->sign = 0;
		n2->number = (n2->number) + 1;
		n2->len -= 1;
		if (type && !bignum_eq(n1, n2))
		{
			n2->sign = 1;
			n2->number = (n2->number) - 1;
			n2->len += 1;
			return (-1);
		}
		if (type && bignum_gt(n1, n2))
		{
			n2->sign = 1;
			n2->number = (n2->number) - 1;
			n2->len += 1;
			bignum_swap(n1, n2);
			return (1);
		}
		else
		{
			n2->number = (n2->number) - 1;
			n2->sign = 1;
			n2->len += 1;
		}
	}
	else
	{
		if (bignum_gt(n1, n2))
		{
			n2->sign = type;
			bignum_swap(n1, n2);
			return (1);
		}
	}
	return (0);
}

t_bignum*			bignum_add_neg(t_bignum* n1, t_bignum* n2, int type)
{
	int			swap;
	size_t		k;
	t_bignum*	dif;

	if ((swap = check_sign(n1, n2, type)) == -1)
		return (bignum_init("0"));
	k = 1 + ((n1->len > n2->len) ? n1->len : n2->len);
	dif = do_work(n1, n2, k, type);
	if (swap)
	{
		bignum_swap(n1, n2);
		n2->sign -= type;
	}
	return (bignum_trunc(dif));
}

t_bignum*			bignum_minus(t_bignum* m, t_bignum* s)
{
	if (m->sign == s->sign)
		return (bignum_add_neg(m, s, 1));
	return (bignum_add_neg(m, s, 0));
}
