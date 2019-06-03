P_SWAP				=	push_swap
CHECKER				=	checker
CC					=	gcc 
FLAGS				=	-Wall -Wextra -Werror

LIBFTINC			=	-I./libft/
LIBFTLINK			=	-L./libft -lft

P_SWAP_SRC_PATH		=	./psh_swap/
P_SWAP_FILES		=	push_swap.c sort_stack.c operations.c create_stack.c \
						check_valid.c check_stack.c operations_name.c utils.c \
						utils1.c
PSW_INCLUDES		=	-I./psh_swap/ $(LIBFTINC)
PSW_OBJ				=	$(P_SWAP_FILES:.c=.o)

CHECKER_SRC_PATH	=	./check/
CHECKER_FILES		=	checker.c ops.c create_stack.c utils.c \
						check_valid.c check_stack.c ops_name.c get_ops.c
CHECKER_INCLUDES	=	-I./check/ $(LIBFTINC)
CH_OBJ				=	$(CHECKER_FILES:.c=.o)

PSW_OBJ				=	$(addprefix $(P_SWAP_SRC_PATH), $(P_SWAP_FILES:.c=.o))
CH_OBJ				=	$(addprefix $(CHECKER_SRC_PATH), $(CHECKER_FILES:.c=.o))

all: libft/libft.a $(P_SWAP) $(CHECKER)

libft/libft.a:
	make -C ./libft

$(P_SWAP): $(PSW_OBJ)
	$(CC) $(FLAGS) $(PSW_INCLUDES) -o $@ $(PSW_OBJ) $(LIBFTLINK)

$(CHECKER): $(CH_OBJ)
	$(CC) $(FLAGS) $(CHECKER_INCLUDES) -o $@ $(CH_OBJ) $(LIBFTLINK)

$(P_SWAP_SRC_PATH)%.o: $(P_SWAP_SRC_PATH)%.c
	$(CC) $(FLAGS) $(PSW_INCLUDES) $(LIBFTINC) -o $@ -c $<

$(CHECKER_SRC_PATH)%.o: $(CHECKER_SRC_PATH)%.c
	$(CC) $(FLAGS) $(CHECKER_INCLUDES) $(LIBFTINC) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -rf $(PSW_OBJ)
	rm -rf $(CH_OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(P_SWAP) $(CHECKER)

re: fclean all
	make -C libft/ re