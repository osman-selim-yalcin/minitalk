SRCS		= printf/ft_printf.a
PRTS		= printf/ft_printf.c printf/ft_printfhelp.c
PRTO 		= $(PRTS:.c=.o)
AR				= ar rcs
RM			= rm -rf

NAME_CL		= client
NAME_SRV	= server
NAME		= IGNOREIT
CFLAGS		= -Wall -Wextra -Werror

SRCS_BCL	= client_bonus.o
SRCS_MCL	= client.o

SRCS_BSRV	= server_bonus.o
SRCS_MSRV	= server.o

all: $(SRCS) $(NAME_CL) $(NAME_SRV)

$(NAME): all

$(SRCS): $(PRTO)
		$(AR) $(SRCS) $(PRTO)
		$(RM)	$(PRTO)

$(NAME_CL): $(SRCS) $(SRCS_MCL)
	gcc $(CFLAGS) $(SRCS) $(SRCS_MCL) -o $(NAME_CL)

$(NAME_SRV): $(SRCS) $(SRCS_MSRV)
	gcc $(CFLAGS) $(SRCS) $(SRCS_MSRV) -o $(NAME_SRV)

$(NAME_CL)_bonus: $(SRCS) $(SRCS_BCL)
	gcc $(CFLAGS) $(SRCS) $(SRCS_BCL) -o $(NAME_CL)_bonus

$(NAME_SRV)_bonus: $(SRCS) $(SRCS_BSRV)
	gcc $(CFLAGS) $(SRCS) $(SRCS_BSRV) -o $(NAME_SRV)_bonus


bonus: $(NAME_CL)_bonus $(NAME_SRV)_bonus 

.c.o:
	gcc $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	@rm -rf $(SRCS_BSRV) $(SRCS_BCL) $(SRCS_MSRV) $(SRCS_MCL)

fclean: clean
	@rm -rf $(NAME_CL)_bonus $(NAME_SRV)_bonus $(NAME_CL) $(NAME_SRV) $(SRCS)

.PHONY: clean fclean all re bonus