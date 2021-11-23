/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbignum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:39:10 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/22 16:55:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGNUM_H
# define BIGNUM_H

# include <stddef.h>
# include <stdlib.h>

# define ADD 1
# define SUBTRACT 0

/*
	Custom data structure to handle whole numbers of arbitrary length
	*
	char* number - string form of value
	size_t alloc_size - size of memory allocated for 'number'
	size_t len - digit length of 'number'
	int sign - set to 1 if negative, 0 if positive
*/
typedef struct		s_bignum
{
	char*			number;
	size_t			alloc_size;
	size_t			len;
	int				sign;
}					t_bignum;

/*
--------------------------------------------------------------------------------
	Contructors & Destructors
--------------------------------------------------------------------------------
*/

/*
	Stores pasred 'number' in an allocated pointer to struct 'bignum'.
	Error input will truncate to last valid digit, or 0.
	*
	** Must be matched with 'bignum_del' to properly free memory *

	number - number represented as a string.
*/
t_bignum*			bignum_init(char* number);

/*
	Frees 'bignum' struct along with the data inside, and sets to 0.
	*
	p - reference to a 'bignum' pointer
*/
void				bignum_del(t_bignum **p);

/*
--------------------------------------------------------------------------------
	Operators
--------------------------------------------------------------------------------
*/

/*
	Adds a2 to a1, and returns an allocated pointer to the sum.
	*
	a1 - pointer to the first addend
	a2 - pointer to the second addend
*/
t_bignum*			bignum_add(t_bignum* a1, t_bignum* a2);

/*
	Subtracts s from m, and returns an allocated pointer to the difference.
	*
	m - pointer to the minuend
	s - pointer to the subtrahend
*/
t_bignum*			bignum_minus(t_bignum* m, t_bignum* s);

/*
	Multiplies m1 by m2, and returns an allocated pointer to the product.
	*
	m1 - pointer to the multiplicand
	m2 - pointer to the multiplier
*/
t_bignum*			bignum_multiply(t_bignum* m1, t_bignum* m2);

/*
	Divides d1 by d2, and returns an allocated pointer to the quotient.
	*
	d1 - pointer to the dividend
	d2 - pointer to the divisor
*/
t_bignum*			bignum_divide(t_bignum* d1, t_bignum* d2);

/*
--------------------------------------------------------------------------------
	Comparators
--------------------------------------------------------------------------------
*/

/*
	Helper Function for comparisons
*/
int					bignum_compare(t_bignum* n1, t_bignum* n2, int type);

/*
	Compares n1 to n2.
	*
	Returns 0 if n1 is greater.
*/
int					bignum_gt(t_bignum* n1, t_bignum* n2);

/*
	Compares n1 to n2
	*
	Returns 0 if n1 is lesser.
*/
int					bignum_lt(t_bignum* n1, t_bignum* n2);

/*
	Compares n1 to n2
	*
	Returns 0 if n1 is equal to n2.
*/
int					bignum_eq(t_bignum* n1, t_bignum* n2);

/*
--------------------------------------------------------------------------------
	Utilities
--------------------------------------------------------------------------------
*/

/*
	Removes excess of preceding zeros from given input
	*
	Returns a pointer to the struct
*/
t_bignum*			bignum_trunc(t_bignum* bignum);

/*
	Swaps data of 'a' and 'b'
*/
void			bignum_swap(t_bignum* a, t_bignum* b);

#endif
