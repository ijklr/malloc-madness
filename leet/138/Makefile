CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wshadow -Wpedantic -Wconversion -Wuninitialized -g -O0 -fsanitize=address,undefined
TARGET = main
SRC =copy_list_with_random_pointer_v1.c copy_list_with_random_pointer_v2.c copy_list_with_random_pointer_test.c build_list.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

