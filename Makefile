NAME = minishell

#Compilador y Flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -I inc/ -I libft/inc/

#Librerias
LIBFT = -L libft -lft

#Archivos de encabezado
HEADER = minishell.h

#Subdirectorios de codigo fuente
BUILTINS = cd echo env exit export pwd unset
ENV = env get_env sort_env shlvl
EXEC = bin builtin exec
MAIN = minishell redir singal
PARSING = line tokens expansions
TOOLS = fd free token expansions parsing

#Archivos fuente
SRC =	src/tools/type.c \
		src/tools/parsing_quotes.c \
		src/tools/token.c \
		src/parsing/tokens.c \


#Archivos objeto
OBJ = $(SRC:%.c=%.o)

#Regla principal
all: $(NAME)

#Compilacion del ejecutable
$(NAME): $(OBJ)
		@echo "\n"
		@make -C libft/
		@echo "\033[0;32mCompiling minishell..."
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
		@echo "\n\033[0mDone !"

#Regla para compilacion de objetos
%.o: %.c
	@printf "\033[0;33mGeneraring minishell objects... %-33.33s\r" $@
	@${CFLAGS} -c $< -o $@

#limpieza de archivos objeto y ejecutables
clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

#Reconstruccion completa
re: fclean all

#Comandos adicionales
test: all
		./minishell
norm:
		norminette $(SRC) includes/$(HEADER)

#Definir como phony para evitar conflictos con archivos reales
.PHONY: clean fclean re test norm