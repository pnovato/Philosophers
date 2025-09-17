NAME = philo
CC = cc
C_FLAGS = -Wall -Werror -Wextra -g
SRC_DIR = ./src/
OBJ_DIR = ./objs/
SRC = main.c time.c 

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "building project..."
	@$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)
	@echo "Philosophers ready!"

# > /dev/null redireciona o stdout, e nao mostra nada 
# 2>&1 redireciona os stderr tbm

clean:
	@echo "Executing cleaning..."
	@rm -rf $(OBJ)
	@echo "Cleaned!"

fclean: clean
	@echo "Executing full cleaning..."
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "Full cleaning done!"

re: fclean all
