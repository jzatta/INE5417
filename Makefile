CC = g++
CFLAGS1 = -Wall -c -Isrc/model/
RM = rm
EXEC = main
TRASH = *.o main

all: main.o user.o
	${CC} -o main user.o main.o
	./${EXEC}
	${RM}	${TRASH}

user.o: src/model/user.cpp src/model/user.hpp
	${CC} ${CFLAGS1} -o user.o src/model/user.cpp

main.o: src/control/main.cpp src/model/user.hpp
	${CC} ${CFLAGS1} -o main.o src/control/main.cpp

clean: 
	${RM} ${TRASH}
