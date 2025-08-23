CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wshadow -Wpedantic -Wconversion -Wuninitialized -g -O0 -fsanitize=address,undefined
SRC = copy_list_with_random_pointer_v1.c copy_list_with_random_pointer_v2.c copy_list_with_random_pointer_test.c build_list.c
OBJ = $(SRC:.c=.o)
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
