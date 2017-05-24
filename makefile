CC = gcc
CFLAGS = -g -Wall -ansi

TARGET = HockeyStats
READFILE = readPlayerFile
LINKEDLIST = linkedList

all: $(TARGET)

$(TARGET): $(TARGET).o $(READFILE).o $(LINKEDLIST).o
	$(CC) $(CFLAGS) -o $(TARGET).out $(TARGET).o $(READFILE).o $(LINKEDLIST).o

$(TARGET).o: $(TARGET).c $(TARGET).h
	$(CC) $(CFLAGS) -c $(TARGET).c

$(READFILE).o: $(READFILE).c $(READFILE).h
	$(CC) $(CFLAGS) -c $(READFILE).c

$(LINKEDLIST).o: $(LINKEDLIST).c $(LINKEDLIST).h
	$(CC) $(CFLAGS) -c $(LINKEDLIST).c

clean:
	$(RM) $(TARGET).out $(TARGET).o $(READFILE).o $(LINKEDLIST).o
