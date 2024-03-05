all: tickets tickets-mutex tickets-atomic tickets-spinlock

tickets: tickets.c
	gcc $< -Wall -Wextra -Werror -lpthread -o $@

tickets-atomic: tickets-atomic.c
	gcc $< -Wall -Wextra -Werror -lpthread -o $@

tickets-spinlock: tickets-spinlock.c
	gcc $< -Wall -Wextra -Werror -lpthread -o $@

tickets-mutex: tickets-mutex.c
	gcc $< -Wall -Wextra -Werror -lpthread -o $@

test: tickets
	./tickets

clean:
	rm -f tickets tickets-mutex tickets-atomic tickets-spinlock
