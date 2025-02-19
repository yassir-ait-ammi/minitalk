CC = cc
CFLAGS = -Wall -Wextra -Werror
CLI = client.c
CLI_EX = client
SERV = server.c
SERV_EX = server
UTILIS = ft_atoi.c ft_putnbr.c

all : $(CLI_EX) $(SERV_EX)

$(SERV_EX): $(SERV)
	$(CC) $(CFLAGS) $< -o $@ $(UTILIS)

$(CLI_EX): $(CLI)
	$(CC) $(CFLAGS) $< -o $@ $(UTILIS)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(CLI_EX) $(SERV_EX)

re : fclean all

.PHONY : all clean fclean re
