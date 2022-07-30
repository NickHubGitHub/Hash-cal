OBJS	= decode.o execute.o hash_insert.o hash_search_E.o hash_update.o main.o hash_delete.o Uinput.o
SOURCE	= decode.cpp execute.cpp hash_insert.cpp hash_search_E.cpp hash_update.cpp main.cpp hash_delete.cpp Uinput.cpp
HEADER	= decode.h execute.h hash_table.hpp Uinput.hpp
OUT	= HCalc.exe
CC	 = g++
FLAGS	 = -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)


Uinput.o: Uinput.cpp
	$(CC) $(FLAGS) Uinput.cpp 

decode.o: decode.cpp
	$(CC) $(FLAGS) decode.cpp 

execute.o: execute.cpp
	$(CC) $(FLAGS) execute.cpp 

hash_insert.o: hash_insert.cpp
	$(CC) $(FLAGS) hash_insert.cpp 

hash_search_E.o: hash_search_E.cpp
	$(CC) $(FLAGS) hash_search_E.cpp 

hash_update.o: hash_update.cpp
	$(CC) $(FLAGS) hash_update.cpp 

hash_delete.o: hash_delete.cpp
	$(CC) $(FLAGS) hash_delete.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)