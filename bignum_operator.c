/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:16:03 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/21 17:08:26 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

//TODO
//figure out how to add negative numbers
//consolidate code

static void			add_carry(char *sum, size_t index)
{
	sum[index] -= 10;
	sum[index - 1] += 1;
}

t_bignum*			bignum_add(t_bignum* a1, t_bignum* a2)
{
	size_t	i; //indexer for a1
	size_t	j; //indexer for a2
	size_t	k; //indexer for sum
	size_t	carry; 
	char	*sum;

	if ((a1->sign == 1 && a2->sign == 0) || a1->sign == 0 && a2->sign == 1)
		return (add_negative(a1, a2));
	k = (a1->len > a2->len) ? a1->len : a2->len;
	k += (((a1->number[0] - '0') + (a2->number[0] - '0')) > 8) ? 1 : 0;
	sum = (char *)malloc(sizeof(char) * k + 1);
	i = 0;
	while (i < k)
	{
		sum[i] = '0';
		++i;
	}
	sum[i] = '\0';
	i = a1->len - 1;
	j = a2->len - 1;
	k -= 1;
	while (1)
	{
		sum[k] += (a1->number[i] - '0') + (a2->number[j] - '0');
		if (sum[k] > '9')
			add_carry(sum, k);
		--k;
		if (i == 0 || j == 0)
			break ;
		--i;
		--j;
	}
	while (!(i == 0 && j == 0))
	{
		if (j != 0)
		{
			--j;
			sum[k] += (a2->number[j] - '0');
		}
		if (i != 0)
		{
			--i;
			sum[k] += (a1->number[i] - '0');
		}
		if (sum[k] > '9')
			add_carry(sum, k);
		--k;
	}
	return (bignum_init(sum));
}

void				bignum_minus(t_bignum* m, t_bignum* s, t_bignum* dif);
void				bignum_multiply(t_bignum* m1, t_bignum* m2, t_bignum* prod);
void				bignum_divide(t_bignum* d1, t_bignum* d2, t_bignum *q);
