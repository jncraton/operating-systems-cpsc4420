CC = gcc
CFLAGS = -O2 -std=c11 -Wall -Wextra
OBJS = main.o add.o sub.o mul.o div.o
TARGET = calculator

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
