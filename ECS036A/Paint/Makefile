# Build file

CC=gcc
RM=rm
CFLAGS=-g -Wall
TARGET=paint.out

all: $(TARGET)

$(TARGET): main.c canvas.c drawing.c commands.c files.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c canvas.c drawing.c commands.c files.c

clean:
	$(RM) $(TARGET)