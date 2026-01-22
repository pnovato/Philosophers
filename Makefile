NAME = philo
CC = cc
C_FLAGS = -Wall -Werror -Wextra -g
SRC_DIR = ./src/
OBJ_DIR = ./objs/
C_FLAGS_TSAN = -fsanitize=thread
SRC = main.c \
time.c \
checker.c \
parse.c \
utils.c \
utils_2.c \
utils_3.c \
dinner.c


OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "building project..."
	@$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)
	@echo "Philosophers ready!"

clean:
	@echo "Executing cleaning..."
	@rm -rf $(OBJ)
	@echo "Cleaned!"

fclean: clean
	@echo "Executing full cleaning..."
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "Full cleaning done!"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

tsan: C_FLAGS += $(C_FLAGS_TSAN)

re: fclean all
