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

t_bignum*			bignum_minus(t_bignum* m, t_bignum* s)
{
	t_bignum*	dif;

	if (m->sign != s->sign) ;
		// return (bignum_difference(m, s));
	// dif = do_work(m, s, SUBTRACT);
	return (bignum_trunc(dif));
}
