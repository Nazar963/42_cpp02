CC = g++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Fixed.cpp bsp.cpp Point.cpp
MAIN = bsp

all: $(MAIN)

$(MAIN):
	$(CC) -g $(CFILES) Fixed.hpp Point.hpp -o $(MAIN)

clean:
	rm $(MAIN)

fclean: clean

re: fclean all

.PHONY: all clean flcean re