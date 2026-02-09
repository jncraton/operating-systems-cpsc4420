all:

%: %.c
	gcc $< -Wall -Wextra -o $@
	ulimit -s 16 && ./$@

clean:
	rm -f overflow
