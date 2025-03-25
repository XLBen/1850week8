# 编译器及编译标志
CC = gcc
CFLAGS = -Wall -Wextra -I./include

# 目录设置
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# 目标可执行文件
TARGET = pgm_tools

# 获取所有源文件
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# 将源文件转换为目标文件路径
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# 默认目标
all: $(TARGET)

# 如果 obj 目录不存在，则创建
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 生成可执行文件
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# 编译源文件为目标文件
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
