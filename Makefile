
CC = g++

LIBS:= -L/usr/local/lib -lmysqlpp -lmysqlclient
INCDIR := src/model/ src/control/ src/vision/ src/mapping/ src/exceptions/ /usr/include/mysql /usr/include/mysql++
CFLAGS1 = $(foreach inc,$(INCDIR),-I$(inc)) $(LIBS) -std=c++11 -Wabi -Wall -c
RM = rm 
EXEC = main
TRASH = *.o main

OBJS = $(shell find src/ -name "*.cpp" -type f -printf "%f\n")
OBJS:= $(subst .cpp,.o,$(OBJS))

.PHONY: all
all: $(EXEC)
	./$(EXEC)
	${RM}	${TRASH}

test:
	@echo $(OBJS)

$(EXEC): ${OBJS}
	${CC} -o $@ $?

%.o: src/control/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

%.o: src/model/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

%.o: src/vision/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

%.o: src/exceptions/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

%.o: src/mapping/%.cpp Makefile
	${CC} ${CFLAGS1} -o $@ $<

.PHONY: clean
clean:
	${RM} ${TRASH}
