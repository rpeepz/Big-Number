NAME	= bignum_test.exe

CFLAGS	= -Wall -Werror -Wextra -g

#PATHS
LIB			= .libft.a
SRC_PATH	= srcs/
HELPER_PATH	= $(SRC_PATH)/helper/

SRCS	= bignum_add.c \
		bignum_copy.c \
		bignum_decrement.c \
		bignum_del.c \
		bignum_divide.c \
		bignum_eq.c \
		bignum_gt.c \
		bignum_increment.c \
		bignum_init.c \
		bignum_lt.c \
		bignum_minus.c \
		bignum_mod.c \
		bignum_multiply.c \
		bignum_swap.c \
		bignum_trunc.c
HELPER	= bignum_compare.c \
		do_dif.c \
		do_quotient.c \
		do_sum.c \
		init_remainder.c \
		init_result.c

.PHONY: clean

all: $(NAME)

clean:
		@rm -f $(OBJ)
		
fclean: clean
		@rm -rf $(OBJ_PATH)
		@rm -rf $(NAME)
		
re: fclean all

$(NAME):
		@printf "make  test\n"
		gcc $(CFLAGS) -o $(NAME) $(addprefix $(SRC_PATH),$(SRCS)) $(addprefix $(HELPER_PATH),$(HELPER)) $(LIB) test.c
		./$(NAME)
