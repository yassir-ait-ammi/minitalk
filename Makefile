CC = gcc
CFLAGS = -Wall -Wextra -Werror #-no-pie
CLI = client.c
CLI_EX = client
SERV = server.c
SERV_EX = server
PRINTF = ft_printf/libftprintf.a

all : $(CLI_EX) $(SERV_EX)

$(SERV_EX): $(SERV)
	$(CC) $(CFLAGS) $< -o $@ $(PRINTF)

$(CLI_EX): $(CLI)
	$(CC) $(CFLAGS) $< -o $@ $(PRINTF)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(CLI_EX) $(SERV_EX)

re : fclean all

.PHONY : all clean fclean re
