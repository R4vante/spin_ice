# compiler & flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

# filenames
TARGET = spinice
OBJS = main.o grid.o mc.o calc.o

# default build rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $<

# clean
clean:
	rm -f *.o $(TARGET)
	rm -f *.dat *.txt

