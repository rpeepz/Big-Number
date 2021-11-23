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

static char			do_dif(size_t* i, size_t* j, char* n1, char* n2)
{
	char	x;

	x = 0;
	if (*i != 0)
	{
		--(*i);
		if (n1[*i] != '-')
			x += (n1[*i] - '0');
	}
	if (*j != 0)
	{
		--(*j);
		if (n2[*j] != '-')
			x -= (n2[*j] - '0');
	}
	return (x);
}

static void			init_result(char* result, size_t k, int sign)
{
	size_t	i;

	i = 0;
	if (sign)
		result[i++] = '-';
	while (i < k)
		result[i++] = '0';
	result[i] = '\0';
}

static t_bignum*	do_work(t_bignum* n1, t_bignum *n2, char* result, size_t k)
{
	size_t	i;
	size_t	j;

	init_result(result, k, (int)n1->sign);
	i = n1->len;
	j = n2->len;
	while (!(i == 0 && j == 0))
	{
		--k;
		result[k] += do_dif(&i, &j, n1->number, n2->number);
		if (k && result[k] < '0')
		{
			result[k] += 10;
			result[k - 1] -= 1;
		}
	}
	return (bignum_init(result));
}

static int			check_sign(t_bignum* n1, t_bignum* n2)
{
	if (n1->sign)
	{
		n1->sign = 0;
		n1->number = (n1->number) + 1;
		n1->len -= 1;
		if (!bignum_eq(n1, n2))
		{
			n1->sign = 1;
			n1->number = (n1->number) - 1;
			n1->len += 1;
			return (-1);
		}
		if (bignum_gt(n1, n2))
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
	else
	{
		n2->sign = 0;
		n2->number = (n2->number) + 1;
		n2->len -= 1;
		if (!bignum_eq(n1, n2))
		{
			n2->sign = 1;
			n2->number = (n2->number) - 1;
			n2->len += 1;
			return (-1);
		}
		if (bignum_gt(n1, n2))
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
	return (0);
}

t_bignum*			bignum_minus(t_bignum* m, t_bignum* s)
{
	int			swap;
	size_t		k;
	char*		result;
	t_bignum*	dif;

	if (m->sign == s->sign)
		return (bignum_add(m, s));
	if ((swap = check_sign(m, s)) == -1)
		return (bignum_init("0"));
	k = (m->len > s->len) ? m->len : s->len;
	result = (char*)malloc(sizeof(char) * (k + 1));
	dif = do_work(m, s, result, k);
	free(result);
	if (swap)
		bignum_swap(m, s);
	return (bignum_trunc(dif));
}
