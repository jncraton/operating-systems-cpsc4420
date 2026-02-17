all: threads thread-args

threads: threads.c 
	gcc $< -lpthread -o $@

thread-args: thread-args.c 
	gcc $< -lpthread -o $@

clean:
	rm -f threads thread-args
