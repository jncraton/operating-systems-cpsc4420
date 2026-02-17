all: threads thread-args

%: %.c 
	gcc $< -Wall -Wextra -lpthread -o $@

clean:
	rm -f threads thread-args
