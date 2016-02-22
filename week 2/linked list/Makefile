# Voorbeeld Makefile
#
# @ Diederich Kroeske, 2011
#

CC	=	gcc
#CC	= 	avr-gcc

TARGET	=	llexample
CFLAGS	=	-Wall

all	:	$(TARGET)

main.o	:	main.c header.h
		$(CC) -c main.c $(CFLAGS)

$(TARGET):	main.o
		$(CC) main.o $(CFLAGS) -o $(TARGET)

clean	:
		rm -f $(TARGET) main.o

info	:
		@echo "$(CC) using $(CFLAGS)"