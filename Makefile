# 编译器
CC = gcc

# 编译选项：开启所有警告，并添加include目录
CFLAGS = -Wall -Iinclude

# 源文件和目标文件
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

# 最终生成的可执行文件名
TARGET = main

all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# 编译每个源文件
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成文件
clean:
	rm -rf obj/*.o $(TARGET)
