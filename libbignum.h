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

/**
	* Custom data structure to handle whole numbers of arbitrary length
	*
	* @param	char* number - string form of value
	* @param	size_t alloc_size - size of memory allocated for 'number'
	* @param	size_t len - digit length of 'number'
	* @param	int sign - set to 1 if negative, 0 if positive
**/
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

/**
	* Stores pasred 'number' into 'bignum' struct.
	* Error input will truncate to last valid digit, or 0.
	*
	* Must be matched with 'bignum_del' to properly free memory
	* @param 	number number represented as a string.
	* @returns 	An allocated pointer to struct 'bignum'.
**/
t_bignum*			bignum_init(char* number);

/**
	* Frees 'bignum' struct along with the data inside, and sets to 0.
	*
	* @param p	reference to a 'bignum' pointer
**/
void				bignum_del(t_bignum **p);

/*
--------------------------------------------------------------------------------
	Operators
--------------------------------------------------------------------------------
*/

/**
	* Adds a2 to a1.
	*
	* @param	a1 pointer to the first addend.
	* @param	a2 pointer to the second addend.
	* @returns	An allocated pointer to the sum.
**/
t_bignum*			bignum_add(t_bignum* a1, t_bignum* a2);

/**
	* Subtracts s from m.
	*
	* @param	m pointer to the minuend.
	* @param	s pointer to the subtrahend.
	* @returns	An allocated pointer to the difference.
**/
t_bignum*			bignum_minus(t_bignum* m, t_bignum* s);

/**
	* Multiplies m1 by m2.
	*
	* @param	m1 pointer to the multiplicand.
	* @param	m2 pointer to the multiplier.
	* @returns	An allocated pointer to the product.
**/
t_bignum*			bignum_multiply(t_bignum* m1, t_bignum* m2);

/**
	* Divides d1 by d2.
	*
	* @param	d1 pointer to the dividend.
	* @param	d2 pointer to the divisor.
	* @returns	An allocated pointer to the quotient.
**/
t_bignum*			bignum_divide(t_bignum* d1, t_bignum* d2);

/*
--------------------------------------------------------------------------------
	Comparators
--------------------------------------------------------------------------------
*/

/**
	* Helper Function for comparisons
**/
int					bignum_compare(t_bignum* n1, t_bignum* n2, int type);

/**
	* Compares n1 to n2.
	*
	* @returns	0 if n1 is greater.
**/
int					bignum_gt(t_bignum* n1, t_bignum* n2);

/**
	* Compares n1 to n2.
	*
	* @returns	0 if n1 is lesser.
**/
int					bignum_lt(t_bignum* n1, t_bignum* n2);

/**
	* Compares n1 to n2.
	*
	* @returns	0 if n1 is equal to n2.
**/
int					bignum_eq(t_bignum* n1, t_bignum* n2);

/*
--------------------------------------------------------------------------------
	Utilities
--------------------------------------------------------------------------------
*/

/**
	* Removes excess of preceding zeros from given input.
	*
	* @returns	A pointer to the modified struct.
**/
t_bignum*			bignum_trunc(t_bignum* bignum);

/**
	* Swaps data of 'a' and 'b'.
**/
void			bignum_swap(t_bignum* a, t_bignum* b);

#endif
