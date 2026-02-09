all:

%: %.c
	gcc $< -Wall -Wextra -o $@
	ulimit -s 32 && ./$@

clean:
	rm -f overflow
