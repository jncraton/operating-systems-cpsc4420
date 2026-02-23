CC = gcc
CFLAGS = -O2 -std=c11 -Wall -Wextra
OBJS = main.o add.o sub.o mul.o div.o
TARGET = calculator

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c
	@echo Compiling main.c
	$(CC) $(CFLAGS) -c $< -o $@

add.o: add.c
	@echo Compiling add.c
	$(CC) $(CFLAGS) -c $< -o $@

sub.o: sub.c
	@echo Compiling sub.c
	$(CC) $(CFLAGS) -c $< -o $@

mul.o: mul.c
	@echo Compiling mul.c
	$(CC) $(CFLAGS) -c $< -o $@

div.o: div.c
	@echo Compiling div.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
