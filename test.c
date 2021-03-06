#include "includes/libbignum.h"
#include "includes/libft.h"
#include <stdio.h>

int main(void) {

	
	t_bignum	*a;
	t_bignum	*b;
	t_bignum	*c;
	char		*number;
	char		*num1;
	char		*num2;

/*
	Testing bignum_init and bignum_del
*/

	printf("-------------------------------\n");
	printf("bignum_init and bignum_del test\n");
	printf("-------------------------------\n");
	
	number = "-987";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "123";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "42";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "0";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-0";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-0a";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "--";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "a";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-a0";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-041a4";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "00000414a";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

/*
	Testing bignum_eq
*/

	printf("-------------------------------\n");
	printf("bignum_eq test\n");
	printf("-------------------------------\n");

	num1 = "123";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "124";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-123";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "A";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "A";
	num2 = "-0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

/*
	Testing bignum_gt
*/

	printf("-------------------------------\n");
	printf("bignum_gt test\n");
	printf("-------------------------------\n");

	num1 = "041";
	num2 = "141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "441";
	num2 = "442";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "124";
	num2 = "12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "100";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124444";
	num2 = "-124445";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-041";
	num2 = "-141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

/*
	Testing bignum_lt
*/
	printf("-------------------------------\n");
	printf("bignum_lt test\n");
	printf("-------------------------------\n");

	num1 = "-2147483648.                 3";
	num2 = "141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "441";
	num2 = "442";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "124";
	num2 = "12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "100";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(flase)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124444";
	num2 = "-124445";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(flase)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-041";
	num2 = "-141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);
	
	num1 = "0";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

/*
	Testing bignum_add
*/

	printf("-------------------------------\n");
	printf("bignum_add test\n");
	printf("-------------------------------\n");

	num1 = "191111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	num2 = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "14";
	num2 = "155";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "1";
	num2 = "420420420420420420420420420420420420420420420420420420420420420420420420420420420420";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "1000000050";
	num2 = "7000000050";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "40000040";
	num2 = "40000059";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "5000000009";
	num2 = "4000000001";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "57";
	num2 = "41";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "150";
	num2 = "50";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "999";
	num2 = "1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "75";
	num2 = "25";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "1175";
	num2 = "1125";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "65555555555555";
	num2 = "25555555555555";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

/*
	Testing bignum_add with negatives
*/

	printf("-------------------------------\n");
	printf("bignum_add (with negatives) test\n");
	printf("-------------------------------\n");

	num1 = "191111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	num2 = "-111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "100000";
	num2 = "-100001";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-100000";
	num2 = "100001";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "179";
	num2 = "-100169";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-169";
	num2 = "100179";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "179";
	num2 = "-169";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-169";
	num2 = "179";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-169";
	num2 = "169";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "0";
	num2 = "14";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-169";
	num2 = "14";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "169";
	num2 = "-14";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-14";
	num2 = "-155";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "1";
	num2 = "-420420420420420420420420420420420420420420420420420420420420420420420420420420420420";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "1000000050";
	num2 = "-7000000050";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-40000040";
	num2 = "40000059";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

/*
	Testing bignum_minus
*/

	printf("-------------------------------\n");
	printf("bignum_minus test\n");
	printf("-------------------------------\n");
	
	num1 = "140000";
	num2 = "1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "45";
	num2 = "-44";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-44";
	num2 = "45";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "1";
	num2 = "140000";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "19999";
	num2 = "-1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "5555555";
	num2 = "666";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-550";
	num2 = "-10";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "0";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "0";
	num2 = "-1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "0";
	num2 = "2";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "2";
	num2 = "4";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-45";
	num2 = "44";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-45";
	num2 = "46";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "46";
	num2 = "45";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "45";
	num2 = "46";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "45";
	num2 = "16";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "222";
	num2 = "-222";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-222";
	num2 = "222";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_minus(a, b);
	printf("%s - %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

/*
	Testing bignum_multiply
*/

	printf("-------------------------------\n");
	printf("bignum_multiply test\n");
	printf("-------------------------------\n");
	
	num1 = "150";
	num2 = "10";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "15";
	num2 = "10";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "123456";
	num2 = "1000";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "100000000";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "10";
	num2 = "1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "10";
	num2 = "-1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-10";
	num2 = "1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-9";
	num2 = "9";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-9";
	num2 = "-9";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_multiply(a, b);
	printf("%s x %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

/*
	Testing bignum_copy
*/

	printf("-------------------------------\n");
	printf("bignum_copy test\n");
	printf("-------------------------------\n");

	num1 = "5";
	num2 = "4200";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	printf("num2: %s, len: %ld, sign: %d\n", b->number, b->len, b->sign);
	bignum_copy(a, b);
	printf("copy num2 %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	bignum_del(&a);
	bignum_del(&b);
	
	num1 = "4200";
	num2 = "5";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	printf("num2: %s, len: %ld, sign: %d\n", b->number, b->len, b->sign);
	bignum_copy(a, b);
	printf("copy num2 %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	bignum_del(&a);
	bignum_del(&b);
	
	num1 = "-4200";
	num2 = "5";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	printf("num2: %s, len: %ld, sign: %d\n", b->number, b->len, b->sign);
	bignum_copy(a, b);
	printf("copy num2 %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	bignum_del(&a);
	bignum_del(&b);

	num1 = "5";
	num2 = "-4200";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	printf("num2: %s, len: %ld, sign: %d\n", b->number, b->len, b->sign);
	bignum_copy(a, b);
	printf("copy num2 %s, len: %ld, sign: %d\n", a->number, a->len, a->sign);
	bignum_del(&a);
	bignum_del(&b);

/*
	Testing bignum_divide
*/

	printf("-------------------------------\n");
	printf("bignum_divide test\n");
	printf("-------------------------------\n");
	
	num1 = "150";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "150";
	num2 = "1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "150";
	num2 = "-1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "0";
	num2 = "150";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "690";
	num2 = "10";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "883474";
	num2 = "227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "883474";
	num2 = "-227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-883474";
	num2 = "227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-883474";
	num2 = "-227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-883474";
	num2 = "-1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_divide(a, b);
	printf("%s / %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

/*
	Testing bignum_mod
*/

	printf("-------------------------------\n");
	printf("bignum_mod test\n");
	printf("-------------------------------\n");
	
	num1 = "150";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %s\n", a->number, b->number, "undefined");
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "150";
	num2 = "1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (150 % 1));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "150";
	num2 = "-1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (150 % (-1)));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "0";
	num2 = "150";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (0 % 150));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "690";
	num2 = "10";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (690 % 10));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "883474";
	num2 = "227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (883474 % 227));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "883474";
	num2 = "-227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (883474 % (-227)));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-883474";
	num2 = "227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (-883474 % 227));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-883474";
	num2 = "-227";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, ((-883474) % (-227)));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-883474";
	num2 = "-1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, ((-883474) % (-1)));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "7";
	num2 = "13";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (7 % 13));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-7";
	num2 = "13";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, ((-7) % 13));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "7";
	num2 = "-13";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, (7 % (-13)));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-7";
	num2 = "-13";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_mod(a, b);
	printf("actual:\t%s %% %s = %d\n", a->number, b->number, ((-7) % (-13)));
	printf("mine:\t%s %% %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	return (0);
}
