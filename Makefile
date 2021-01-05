CC = g++

TARGET = todo

app: $(TARGET).o
	$(CC) $(TARGET).cpp -o $(TARGET).out