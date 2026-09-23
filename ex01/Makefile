NAME     = Bureaucrat

CC       = c++

CFLAGS   = -Wall -Wextra -Werror -std=c++98

OBJ_DIR  = obj/

SRCS     =	main.cpp \
			src/Bureaucrat.cpp \
			src/Form.cpp

OBJ = $(patsubst src/%.cpp, $(OBJ_DIR)%.o, $(SRCS))

MAKE_DIR = mkdir -p
 
all:            $(NAME)
 
$(NAME):        $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $@
		@echo -e "\033[1;92m======== project compiled ========\033[0m"
 
$(OBJ_DIR)%.o: src/%.cpp
		@$(MAKE_DIR) $(OBJ_DIR)
		@$(CC) $(CFLAGS) -I./inc -c $< -o $@
 
clean:
		@rm -rf $(OBJ_DIR)
		@echo -e "\033[1;35m======== object files removed ========\033[0m"
 
fclean:         clean
		@rm -rf $(NAME)
		@echo -e "\033[1;36m======== executable removed ========\033[0m"
 
re:             fclean all

.PHONY:         clean fclean all re