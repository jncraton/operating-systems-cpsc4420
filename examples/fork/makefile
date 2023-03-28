all: fork exec forkexec kill

%: %.c
	gcc -Wextra -Wall $< -o $@

clean:
	rm -f fork exec forkexec kill
