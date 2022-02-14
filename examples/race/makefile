all: tickets tickets-mutex

tickets: tickets.c 
	gcc $< -Wall -Wextra -Werror -lpthread -o $@

tickets-mutex: tickets-mutex.c 
	gcc $< -Wall -Wextra -Werror -lpthread -o $@

test: tickets
	./tickets

clean:
	rm -f tickets tickets-mutex
