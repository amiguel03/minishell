NAME = minishell

#------------------------------------------------------------------------------#

# Compilador a utilizar (gcc, clang, etc)
CC = gcc
# Flags de compilacion (agregar los que se necesiten) -O2 para pruebas extra
CFLAGS = -g3 -Wall -Wextra -Werror# -Wpedantic -Wshadow -Wformat -Wnull-dereference -Wconversion -Wstrict-overflow -Wsign-conversion -Wimplicit-fallthrough=5 -Wdouble-promotion -Wvla -Wformat-security -Wcast-align=strict -Wredundant-decls -Wlogical-op -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Winit-self -Wuninitialized -Wbad-function-cast -Wmissing-field-initializers

# Incluir archivos de dependencia
-include $(OBJS:.o=.d)

#------------------------------------------------------------------------------#

# Archivos fuente (agregar los que se necesiten, separar por carpetas)


MAIN_SRCS = 	src/utils/headline.c \
				src/main/main.c\


SRCS =			$(MAIN_SRCS) \

#------------------------------------------------------------------------------#

# Archivos objeto (no tocar)
OBJS = $(SRCS:.c=.o)
# Directorio de los archivos objeto (no tocar)
OBJDIR = $(NAME)_objects
# Directorio de la libft. Si se usa, descomentar la linea
LIBFT_DIR = ./libft
# Libreria a utilizar. Si se usa, descomentar la linea
LIBFT = $(LIBFT_DIR)/libft.a

#------------------------------------------------------------------------------#

# Colores para el make.

# (Elige los colores que mas te gusten para el makefile. Elimina los que no
# necesites.)

# Recuerda siempre usar $(RESET) al final de tu mensaje para restablecer los
# colores a los valores predeterminados de la terminal.
RESET = \033[0m

# Regular
RED = \033[0;31m
GREEN = \033[0;32m
CYAN = \033[0;36m

# Bold
BOLD_RED = \033[1;31m
BOLD_GREEN = \033[1;32m
BOLD_PURPLE = \033[1;35m

# More colors
B_C = \033[1;36m
YELLOW = \033[0;33m
BOLD_YELLOW = \033[1;33m
BLUE = \033[0;34m
BOLD_BLUE = \033[1;34m
MAGENTA = \033[0;35m
BOLD_MAGENTA = \033[1;35m
WHITE = \033[0;37m
BOLD_WHITE = \033[1;37m

#------------------------------------------------------------------------------#

LAST_MAKE_HAD_COMPILATION := 0

# Reglas del make (no tocar)

# La regla all compila el ejecutable
all: $(LIBFT) $(NAME)
	@if [ "$(LAST_MAKE_HAD_COMPILATION)" = "1" ]; then \
		clear; \
	else \
		echo "╔══════════╝ ╚══════════╝ ╚══════════╝ ╚══════════╝ ╚══════════╗"; \
		echo "║ $(B_C)(┌ಠ_ಠ)\t¡$(NAME) compilado con éxito!!\t(ಠ_ಠ┐)$(RESET) ║"; \
		echo "╚══════════════════════════════════════════════════════════════╝"; \
		sleep 1; \
		clear; \
	fi
	@$(eval LAST_MAKE_HAD_COMPILATION := 1)

# La regla $(NAME) compila el ejecutable con los archivos objeto creados
$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(BOLD_GREEN)¡Objetos creados!\n$(RESET)"
	@echo "$(CYAN)Compilando $(NAME)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $(addprefix $(OBJDIR)/, $(OBJS)) -lreadline $(LIBFT)

# La regla %.o compila los archivos objeto
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@
	@$(eval LAST_MAKE_HAD_COMPILATION := 1)

# La regla $(OBJDIR) crea el directorio de los archivos objeto
$(OBJDIR):
	@echo "$(CYAN)Creando directorio de objetos...\n$(RESET)"
	@mkdir -p $(OBJDIR)/src/*
	@echo "$(BOLD_GREEN)¡Directorio de objetos creado!\n$(RESET)"
	@echo "$(CYAN)Creando objetos...\n$(RESET)"


# La regla libft compila la libft. Si se usa, descomentar las siguientes
# dos lineas
$(LIBFT):
	@make -sC $(LIBFT_DIR)

# La regla libft_clean elimina los archivos objeto de la libft. Si se usa,
# descomentar las siguientes dos lineas
libft_clean:
	@make -sC $(LIBFT_DIR) clean

# La regla libft_clean elimina los archivos objeto de la libft y el ejecutable.
# Si se usa, descomentar las siguientes dos lineas
libft_fclean:
	@make -sC $(LIBFT_DIR) fclean

# La regla clean elimina todos los archivos objeto y su directorio. Si se usa la
# libft, descomentar la linea libft_clean
clean: libft_clean
	@echo "$(RED)Eliminando archivos objeto...\n$(RESET)"
	@rm -rf $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(BOLD_RED)¡Todos los archivos objeto han sido eliminados!\n$(RESET)"
	@echo "$(RED)Eliminando directorio de objetos...\n$(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(BOLD_RED)¡Directorio de objetos eliminado!\n$(RESET)"
	@clear

# La regla fclean elimina todos los archivos objeto y el ejecutable. Si se usa
# la libft, descomentar la linea libft_fclean
fclean: clean libft_fclean
	@echo "$(RED)Eliminando ejecutable...\n$(RESET)"
	@rm -rf $(NAME)
	@echo "$(BOLD_RED)¡El ejecutable ha sido eliminado!\n$(RESET)"
	@sleep 1
	@clear

# La regla re elimina todo y compila nuevamente
re: fclean all

# La regla init inicializa el proyecto
init:
	@bash -c 'read -p "Quieres ver los comandos de los que dispone este Makefile? [y/n]: " answer; \
	if [ "$$answer" = "y" ]; then \
		make --no-print-directory help; \
		read -p "Para continuar, presiona enter..."; \
	else \
		echo "Puedes ver los comandos con '\''make help'\'' en cualquier momento"; \
	fi'

# La regla test compila y ejecuta el programa con los argumentos que le pases
test: re
	@read -p "¿Cuántos argumentos quieres introducir? " num_args; \
	for ((i=1; i<=num_args; i++)); do \
		read -p "Introduce el argumento $$i: " arg; \
		args+=" $$arg"; \
	done; \
	./$(NAME)$$args

# Versión
VERSION = 1.10.22
version:
	@echo "Version: $(VERSION)"

# La regla git agrega, hace commit y hace push
git: fclean
	git add .
	git status
	@read -p "Quieres continuar? [y/n]: " answer; \
	if [ "$$answer" = "y" ]; then \
		read -p "Mensaje para el commit: " message; \
		git commit -m "$$message"; \
		git push; \
		clear; \
		echo "╔══════════════════════════════════════════════════════╗"; \
		echo "║ $(BOLD_GREEN)(┌ಠ_ಠ)\t ¡¡¡Git push realizado!!! \t(ಠ_ಠ┐)$(RESET) ║"; \
		echo "╚══════════════════════════════════════════════════════╝"; \
		sleep 0.5; \
		clear; \
	else \
		clear; \
		echo "╔════════════════════════════════════════════════════════╗"; \
		echo "║ $(BOLD_RED)(҂◕︵◕)\t¡¡¡Git push no realizado!!!\t (҂◕︵◕)$(RESET) ║"; \
		echo "╚════════════════════════════════════════════════════════╝"; \
		sleep 0.5; \
		clear; \
	fi

# La regla norm comprueba la norminette en las SRCS y en el .h
norm:
	@norminette $(SRCS) minishell.h | grep -v Norme -B1 || true

# La regla help muestra las reglas del make
help:
	@echo "\n"
	@echo ""
	@echo "$(BOLD_PURPLE)Reglas incluidas en el Makefile:$(RESET)"
	@echo ""
	@echo "  $(CYAN)all$(RESET)	-> Compila el ejecutable"
	@echo "  $(CYAN)clean$(RESET)	-> Elimina los archivos objeto"
	@echo "  $(CYAN)fclean$(RESET)-> Elimina los archivos objeto y el ejecutable"
	@echo "  $(CYAN)re$(RESET)	-> Elimina todo y compila nuevamente"
	@echo "  $(CYAN)init$(RESET)	-> Inicializa el proyecto"
	@echo "  $(CYAN)test$(RESET)	-> Compila y ejecuta el promgrama con los argumentos que le pases"
	@echo "  $(CYAN)git$(RESET)	-> Agrega, hace commit y hace push"
	@echo "  $(CYAN)norm$(RESET)	-> Ejecuta Norminette"
	@echo "  $(CYAN)help$(RESET)	-> Muestra las reglas del make"
	@echo ""

# La regla .PHONY indica que no hay un archivo llamado all, clean, fclean, 
# git, re, norm, help o libft
.PHONY: all clean fclean git re libft norm help
#-----------------------------------------------------------