/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:16:03 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/21 19:21:53 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

//TODO
//figure out how to add negative numbers to positive numbers
//consolidate code

t_bignum*			add_negative(t_bignum* a1, t_bignum* a2)
{
	void*	p;

	p = a1;
	a1 = a2;
	a2 = a1;
	return (bignum_init("0"));
}

t_bignum*			bignum_add(t_bignum* a1, t_bignum* a2)
{
	size_t	i; //indexer for a1
	size_t	j; //indexer for a2
	size_t	k; //indexer for sum
	char	*sum;

	if ((a1->sign == 1 && a2->sign == 0) || a1->sign == 0 && a2->sign == 1)
		return (add_negative(a1, a2));
	k = (a1->len > a2->len) ? a1->len : a2->len;
	k += (((a1->number[0] - '0') + (a2->number[0] - '0')) > 8) ? 1 : 0;
	sum = (char *)malloc(sizeof(char) * k + 1);
	i = 0;
	if (a1->sign == 1 && a2->sign == 1)
		sum[i++] = '-';
	while (i < k)
		sum[i++] = '0';
	sum[i] = '\0';
	i = a1->len;
	j = a2->len;
	while (!(i == 0 && j == 0))
	{
		--k;
		if (j != 0)
			sum[k] += (a2->number[--j] == '-') ? 0 : (a2->number[j] - '0');
		if (i != 0)
			sum[k] += (a1->number[--i] == '-') ? 0 : (a1->number[i] - '0');
		if (sum[k] > '9')
		{
			sum[k] -= 10;
			sum[k - 1] += 1;
		}
	}
	return (bignum_init(sum));
}

void				bignum_minus(t_bignum* m, t_bignum* s, t_bignum* dif);
void				bignum_multiply(t_bignum* m1, t_bignum* m2, t_bignum* prod);
void				bignum_divide(t_bignum* d1, t_bignum* d2, t_bignum *q);
