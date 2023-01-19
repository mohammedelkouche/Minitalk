# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 17:06:56 by mel-kouc          #+#    #+#              #
#    Updated: 2023/01/19 22:50:52 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_CLIENT = Mandatory/client.c Mandatory/utile.c Mandatory/atoi.c
SRCS_SEREVR = Mandatory/server.c Mandatory/utile.c Mandatory/atoi.c

SRCS_CLIENT_BONUS = bonus/client_bonus.c bonus/utile_bonus.c bonus/atoi_bonus.c
SRCS_SERVER_BONUS = bonus/server_bonus.c bonus/utile_bonus.c bonus/atoi_bonus.c

CLIENT_OBJ = $(SRCS_CLIENT:.c=.o)
SERVER_OBJ = $(SRCS_SERVER:.c=.o)

CLIENT_OBJ_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
SERVER_OBJ_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT)
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SERVER_OBJ)
	@cc -Werror -Wextra -Wall $(SERVER_OBJ) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	@cc -Werror -Wextra -Wall $(CLIENT_OBJ) -o $(CLIENT)

$(SERVER_BONUS): $(SERVER_OBJ_BONUS)
	@cc -Werror -Wextra -Wall $(SERVER_OBJ_BONUS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS)
	@cc -Werror -Wextra -Wall $(CLIENT_OBJ_BONUS) -o $(CLIENT_BONUS)


# %.o:%.c man/minitalk.h bonus/minitalk_bonus.h
# 	@cc -Werror -Wextra -Wall -c $^ -o $@

clean:
	rm -f  $(SERVER_OBJ) $(CLIENT_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all