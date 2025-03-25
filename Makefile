# 编译器及编译标志
CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

TARGET = pgm_tools

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(TARGET)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
