# Big-Number
`t_bignum` is a structure that can hold any size integer within (-inf, inf). It stores decimal digits in a string, with the lower power digits at lower indices and the higher power digits at higher indices. Math operations are provided on `t_bignum`'s.  

## BIGNUM Functions

### Constructor

- `t_bignum *bignum_init(char *number)`

### Conditional "Operators"

All the functions here take two `t_bignum *` as arguments and return 0 for true, 1 for false.  

- `bignum_gt`
- `bignunm_lt`
- `bignum_eq`

### Arithmetic Operators

All the functions here take two `t_bignum *` as arguments and return the result of the requested arithmetic operation as a **newly malloc'd** `t_bignum *`.  

- `bignum_add`
- `bignum_minus`
- `bignum_multiply`
- `bignum_divide`
- `bignum_mod`

### Destructor

- `bignum_del(t_bignum **p)`

### Utility

- `bignum_truc(t_bignum *bignum)` returns the bignum with preceeding 0's stripped.
- `bignum_swap(t_bignum *a, t_bignum *b)` swaps two large integers.
- `bignum_increment(t_bignum *n)` returns n with an incremented value.
- `bignum_decrement(t_bignum *n)` returns n with a decremented value.
- `bignum_copy(t_bignum *dst, t_bignum *src)` returns `dst` with info from `src`.

## Credits

All code is written by me.
