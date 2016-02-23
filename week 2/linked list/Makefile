# Voorbeeld Makefile
#
# @ Diederich Kroeske, 2011
#

CC	=	C:\Program Files\mingw-w64\x86_64-5.3.0-posix-seh-rt_v4-rev0\mingw64\bin\gcc
#CC	= 	avr-gcc
#CC	=	gcc

TARGET	=	main
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