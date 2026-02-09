all:

%: %.c
	gcc $< -Wall -Wextra -o $@
	ulimit -s 32 && ./$@
