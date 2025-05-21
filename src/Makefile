# compiler & flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -lm

# filenames
TARGET = spinice
OBJS = main.o utils.o 

# default build rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

# clean
clean:
	rm -f *.o $(TARGET)
