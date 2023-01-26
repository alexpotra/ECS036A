# Build file

CC=gcc
RM=rm
CFLAGS=-g -Wall
TARGET=determinant.out

all: $(TARGET)

$(TARGET): main.c matrix.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c matrix.c
clean:
	$(RM) $(TARGET)