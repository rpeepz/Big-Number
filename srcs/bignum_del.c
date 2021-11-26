/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:16:44 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/23 11:17:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libbignum.h"

void			bignum_del(t_bignum** p)
{
	free((*p)->number);
	(*p)->number = NULL;
	(*p)->alloc_size = 0;
	(*p)->len = 0;
	(*p)->sign = 0;
	free(*p);
	*p = NULL;
}
