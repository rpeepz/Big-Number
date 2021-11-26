/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:53:16 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/23 14:32:05 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libbignum.h"

static t_bignum*	do_work(t_bignum* n1, t_bignum *n2, size_t k, int type)
{
	size_t		i;
	size_t		j;
	char*		result;
	t_bignum*	bignum;

	result = (char*)malloc(sizeof(char) * (k + 1));
	init_result(result, k, (int)n1->sign);
	i = n1->len;
	j = n2->len;
	while (!(i == 0 && j == 0))
	{
		--k;
		result[k] += (type ? do_dif(&i, &j, n1->number, n2->number) :\
							do_sum(&i, &j, n1->number, n2->number));
		if (type && k && result[k] < '0')
		{
			result[k] += 10;
			result [k - 1] -= 1;
		}
		else if (!type && k && result[k] > '9')
		{
			result[k] -= 10;
			result[k - 1] += 1;
		}
	}
	bignum = bignum_init(result);
	free(result);
	return (bignum);
}

static void			check_revert(t_bignum* n, int step)
{
	if (step == 0)
	{
		n->sign = 0;
		n->number = (n->number) + 1;
		n->len -= 1;
	}
	else if (step == 1)
	{
		n->sign = 1;
		n->number = (n->number) - 1;
		n->len += 1;
	}
}

static int			check_sign(t_bignum* n1, t_bignum* n2, int type, int l)
{
	int		ret;

	check_revert(n1, 0);
	if (type && !bignum_eq(n1, n2))
	{
		check_revert(n1, 1);
		ret = -1;
	}
	if ((!l && type && bignum_gt(n1, n2)) || (l && type && bignum_lt(n1, n2)))
	{
		check_revert(n1, 1);
		bignum_swap(n1, n2);
		ret = 1;
	}
	else
	{
		check_revert(n1, 1);
		ret = 0;
	}
	return (ret);
}

t_bignum*			bignum_add_neg(t_bignum* n1, t_bignum* n2,\
								int type, int swap)
{
	size_t		k;
	t_bignum*	dif;

	if (n1->sign)
		swap = check_sign(n1, n2, type, 0);
	else if (n2->sign)
		swap = check_sign(n2, n1, type, 1);
	else if (type && !bignum_eq(n1, n2))
		swap = -1;
	else if (bignum_gt(n1, n2))
	{
		n2->sign = type;
		bignum_swap(n1, n2);
		swap = 1;
	}
	if (swap == -1)
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
		return (bignum_add_neg(m, s, 1, 0));
	return (bignum_add_neg(m, s, 0, 0));
}
