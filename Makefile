CC := clang++
CFLAGS := -std=c++17 -v
TARGET := main

SRCS := main.cpp $(wildcard sources/*.cpp)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -g $(SRCS) -o $@ $^ $(CFLAGS)
clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean