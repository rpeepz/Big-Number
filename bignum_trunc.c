/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_trunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:38:40 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/23 08:58:50 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

t_bignum*	bignum_trunc(t_bignum* bignum)
{
	size_t	i;
	size_t	j;

	if (bignum->len > 1)
	{
		i = bignum->sign;
		j = bignum->sign;
		while (bignum->number[i] == '0')
			++i;
		while (i <= bignum->alloc_size)
		{
			bignum->number[j] = bignum->number[i];
			++j;
			++i;
		}
		bignum->len = j;
	}
	return (bignum);
}
