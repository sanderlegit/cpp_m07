# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                          e8'   8   '8e           #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/11 15:02:04 by averheij      #+#    #+#                  #
#    Updated: 2021/11/22 16:36:25 by dries               **ee8ee**             #
#                                                                              #
# **************************************************************************** #

NAME		=	array
CPPFILES	=	main.cpp
OBJDIR		=	objects
OFILES		=	$(CPPFILES:%.cpp=$(OBJDIR)/%.o)
OS      	=   $(shell uname)
ifeq ($(OS),Linux)
	CC		=	g++
else
	CC		=	clang++
endif
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic -g
ifeq ($(DEBUG), 1)
	FLAGS	+= -fsanitize=address
endif
#FLAGS =

all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OFILES)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all
