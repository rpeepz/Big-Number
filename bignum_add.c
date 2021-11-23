/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:16:03 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/23 11:13:20 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

static char			do_sum(size_t* i, size_t* j, char* n1, char* n2)
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
			x += (n2[*j] - '0');
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

static t_bignum*	do_work(t_bignum* n1, t_bignum* n2, char* result, size_t k)
{
	size_t	i;
	size_t	j;

	init_result(result, k, n1->sign);
	i = n1->len;
	j = n2->len;
	while (!(i == 0 && j == 0))
	{
		--k;
		result[k] += do_sum(&i, &j, n1->number, n2->number);
		if (result[k] > '9')
		{
			result[k] -= 10;
			result[k - 1] += 1;
		}
	}
	return (bignum_init(result));
}

t_bignum*			bignum_add(t_bignum* a1, t_bignum* a2)
{
	size_t		k;
	char*		result;
	t_bignum*	sum;
	
	k = 1 + ((a1->len > a2->len) ? a1->len : a2->len);
	result = (char *)malloc(sizeof(char) * (k + 1));
	if (a1->sign != a2->sign) ;
		// return (bignum_difference(a1, a2));
	sum = do_work(a1, a2, result, k);
	free(result);
	return (bignum_trunc(sum));
}
