#
#
CC=g++
#
CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient



all: winedb

winedb: winedb.o dbconnect.o wineOperations.o
	$(CC) winedb.o dbconnect.o wineOperations.o -o winedb $(LFLAGS)

dbconnect.o: dbconnect.cpp
	$(CC) $(CFLAGS) dbconnect.cpp

winedb.o: winedb.cpp wineOperations.h
	$(CC) $(CFLAGS) winedb.cpp

wineOperations.o: wineOperations.cpp wineOperations.h
	$(CC) $(CFLAGS) wineOperations.cpp

clean:
	rm *.o winedb

run:
	./winedb
