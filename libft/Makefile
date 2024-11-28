#------------------------------------------------------------------------------#
#******************************************************************************#
#********************************* C MAKEFILE *********************************#
#******************************************************************************#
#------------------------------------------------------------------------------#

# Nombre del ejecutable a crear (sin espacios)
NAME = libft.a

#------------------------------------------------------------------------------#

# Compilador a utilizar (gcc, clang, etc)
CC = gcc
# Flags de compilacion (agregar los que se necesiten)
CFLAGS = -Wall -Wextra -Werror -g3

#------------------------------------------------------------------------------#

# Archivos fuente (agregar los que se necesiten)
SRCS =	ft_atoi.c \
		ft_itoa.c \
		ft_bzero.c \
		ft_split.c \
		ft_strlen.c \
		ft_memset.c \
		ft_memchr.c \
		ft_strchr.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_intlen.c \
		ft_memcpy.c \
		ft_substr.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strnstr.c \
		ft_isspace.c \
		ft_strncmp.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstiter.c \
		ft_lstclear.c \
		ft_striteri.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_lstdelone.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \

#------------------------------------------------------------------------------#
 
# Archivos objeto (no tocar)
OBJS = $(SRCS:.c=.o)
# Directorio de los archivos objeto (no tocar)
OBJDIR = libft_objects

#------------------------------------------------------------------------------#

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

all: $(NAME)
	@if [ "$(LAST_MAKE_HAD_COMPILATION)" = "1" ]; then \
		clear; \
	else \
		echo "╔══════════════════════════════════════════════════════════════╗"; \
		echo "║ $(B_C)(┌ಠ_ಠ)\t ¡$(NAME) compilado con éxito!!\t\t(ಠ_ಠ┐)$(RESET) ║"; \
		echo "╚══════════╗ ╔══════════╗ ╔══════════╗ ╔══════════╗ ╔══════════╝"; \
	fi
	@$(eval LAST_MAKE_HAD_COMPILATION := 1)
	
# La regla $(NAME) compila el ejecutable con los archivos objeto creados 
$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)¡Objetos de $(NAME) creados!\n$(RESET)"
	@echo "$(CYAN)Compilando $(NAME)...\n$(RESET)"
	@ar -crs $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(@D)
	@echo "$(CC) $(CFLAGS) -MMD -c $< -o $@"
	$(CC) $(CFLAGS) -MMD -c $< -o $@
	@$(eval LAST_MAKE_HAD_COMPILATION := 1)

# La regla $(OBJDIR) crea el directorio de los archivos objeto
$(OBJDIR):
	@echo "$(CYAN)Creando directorio de objetos de $(NAME)...\n$(RESET)"
	@mkdir -p $(OBJDIR)
	@echo "$(GREEN)¡Directorio de objetos de $(NAME) creado!\n$(RESET)"
	@echo "$(CYAN)Creando objetos de $(NAME)...\n$(RESET)"

# La regla clean elimina todos los archivos objeto y el directorio
clean:
	@echo "$(RED)Eliminando archivos objeto de $(NAME)...\n$(RESET)"
	@rm -rf $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)¡Todos los archivos objeto de $(NAME) han sido eliminados!\n$(RESET)"
	@echo "$(RED)Eliminando directorio de objetos de $(NAME)...\n$(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)¡Directorio de objetos de $(NAME) eliminado!\n$(RESET)"

# La regla fclean elimina todos los archivos objeto y el ejecutable
fclean: clean
	@echo "$(RED)Eliminando $(NAME)...\n$(RESET)"
	@rm -rf $(NAME)
	@echo "$(GREEN)¡$(NAME) ha sido eliminado!\n$(RESET)"

# La regla re elimina todo y compila nuevamente
re: fclean all

# La regla git agrega, hace commit y hace push
git:
	git add .
	git status
	@read -p "Quieres continuar? [y/n]: " answer; \
	if [ "$$answer" = "y" ]; then \
		read -p "Mensaje para el commit: " message; \
		git commit -m "$$message"; \
		git push; \
		echo "╔══════════════════════════════════════════════════════════════╗"; \
		echo "║ $(BOLD_GREEN)(┌ಠ_ಠ)\t\t ¡¡¡Git push realizado!!! \t(ಠ_ಠ┐)$(RESET) ║"; \
		echo "╚══════════╗ ╔══════════╗ ╔══════════╗ ╔══════════╗ ╔══════════╝"; \
	else \
		echo "$(BOLD_RED)(҂◕︵◕) \t\t¡¡¡Git push no realizado \t(҂◕︵◕)!!!$(RESET)"; \
	fi

# La regla .PHONY indica que no hay un archivo llamado all, clean, fclean o re
.PHONY: all clean fclean re git
#------------------------------------------------------------------------------#