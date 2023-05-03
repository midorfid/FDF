NAME = libft.a
SRC =	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_strchr.c		\
		ft_strncmp.c	\
		ft_strdup.c		\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strlcat.c	\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_putchar_fd.c	\
		ft_striteri.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\

OBJFILESBONUS = $(SRCB:.c=.o)
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
PRINTF			= ft_printf/ft_printf.o ft_printf/ft_printf_ptr.o \
				  ft_printf/ft_printf_unsign.o ft_printf/ft_printf_hex.o \
				  ft_printf/ft_itoa.o ft_printf/utils.o \

GET_NEXT_LINE 	= Get_Next_Line/get_next_line.o Get_Next_Line/get_next_line_utils.o \

all: $(NAME)

$(NAME) : $(OBJFILES) $(GET_NEXT_LINE) $(PRINTF)
	ar -rcs $@ $(OBJFILES) $(PRINTF) $(GET_NEXT_LINE)

$(PRINTF):
				make -C ft_printf

$(GET_NEXT_LINE):
				make -C Get_Next_Line

clean:
	rm -rf $(OBJFILES)
	make clean -C ft_printf
	make clean -C Get_Next_Line

fclean: clean
	rm -rf $(NAME)
	make fclean -C ft_printf
	make fclean -C Get_Next_Line

re: fclean all

.PHONY: all clean fclean re
