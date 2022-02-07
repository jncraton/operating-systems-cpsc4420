all: tickets

tickets: tickets.c 
	gcc $< -Wall -Wextra -Werror -lpthread -o $@

test: tickets
	./tickets

clean:
	rm -f sum
