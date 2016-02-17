CC	= 	gcc
#CC	= 	avr-gcc

TARGET	=	llist	
CFLAGS	= 	-Wall -O2

all	:	$(TARGET)

main.o	:	main.c Header.h
		$(CC) -c main.c $(CFLAGS)

$(TARGET):	main.o
		$(CC) main.o $(CFLAGS) -o $(TARGET)

clean	:
		rm -f $(TARGET) main.o

info	:
		@echo "$(CC) using $(CFLAGS)"
