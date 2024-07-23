# Compiler and Compiler Flags
CC = gcc
CFLAGS = -Wall -g -std=c99
LDFLAGS =

# Target executable name
TARGET = add-nbo

# Source and Object files
SRC = add-nbo.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Target build
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Object files from source
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: all clean








