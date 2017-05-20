CC = gcc
CFLAGS = -g -Wall -ansi

TARGET = HockeyStats
READFILE = readPlayerFile

all: $(TARGET)

$(TARGET): $(TARGET).o $(READFILE).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o $(READFILE).o

$(TARGET).o: $(TARGET).c $(TARGET).h
	$(CC) $(CFLAGS) -c $(TARGET).c

$(READFILE).o: $(READFILE).c $(READFILE).h player.h
	$(CC) $(CFLAGS) -c $(READFILE).c

clean:
	$(RM) $(TARGET)
