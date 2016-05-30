
CC = g++
CFLAGS1 = -std=c++11 -Wabi -Wall -c -Isrc/model/ -Isrc/control/ -Isrc/vision/
RM = rm 
EXEC = main
TRASH = *.o main

OBJ=main.o user.o superUser.o usermanager.o commonUser.o manager.o
OBJ+=filemanager.o File.o Log.o GUI.o Control.o

.PHONY: all
all: ${OBJ}
	${CC} -o main $?
	./${EXEC}
	${RM}	${TRASH}

%.o: src/control/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

%.o: src/model/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

%.o: src/vision/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

.PHONY: clean
clean:
	${RM} ${TRASH}
