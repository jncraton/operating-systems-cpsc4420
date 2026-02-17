all: threads thread-args

%: %.c 
	gcc $< -lpthread -o $@

clean:
	rm -f threads thread-args
