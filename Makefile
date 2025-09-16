NAME = philosophers
CC = cc
C_FLAGS = -Wall -Werror -Wextra -g
SRC_DIR = ./philo/src/
OBJ_DIR = ./objs/
SRC = main.c 

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(C_FLAGS) -c $< -o $@ 2>error.txt

$(NAME): $(OBJ)
	@echo "building project..."
	@$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)
	@echo "Philosophers ready!"

# > /dev/null redireciona o stdout, e nao mostra nada 
# 2>&1 redireciona os stderr tbm

clean:
	@echo "Executing cleaning..."
	@rm -rf $(OBJ) > /dev/null 2>&1 > error.txt
	@echo "Cleaned!"

fclean: clean
	@echo "Executing full cleaning..."
	@rm -f $(NAME) > /dev/null 2>&1
	@rm -rf $(OBJ_DIR) > /dev/null 2>&1
	@echo "Full cleaning done!"

re: fclean all
