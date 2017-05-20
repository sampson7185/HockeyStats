CC = gcc
CFLAGS = -g -Wall -ansi

TARGET = readPlayerFile

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).c $(TARGET).h Player.h
	$(CC) $(CFLAGS) -c $(TARGET).c

clean:
	$(RM) $(TARGET)
