NAME = philo
CC = cc
C_FLAGS = -Wall -Werror -Wextra -g
PHILO_DIR = ./philo/
OBJ_DIR = ./objs/
PHILO = main.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all : &(NAME)

$(OBJ_DIR)%.o: $(PHILO_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(C_FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "building project..."
	@$(CC) $(C_FLAGS) $(OBJ) -o $(NAME) > /dev/null 2>&1
	@echo "Philosophers ready!"

# > /dev/null redireciona o stdout, e nao mostra nada 
# 2>&1 redireciona os stderr tbm

clean:
	@echo "Executing cleaning..."
	@rm -rf $(OBJ) > /dev/null 2>&1
	@echo "Cleaned!"

fclean: clean
	@echo "Executing full cleaning..."
	@rm -rf $(NAME) $(OBJ_DIR) > /dev/null 2>&1
	@echo "Full cleaning done!"

re: fclean all
