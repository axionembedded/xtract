CC=arm-none-eabi-gcc
WARN=-Wall -Wextra -Werror
INC=-I./include
SRC=src/xtract.c
WARNS=-Wall -Wextra -Werror
OUT=./output/xtract.o
DBG=-ggdb
MKDIR=mkdir -p output

debug: default

default:
	$(MKDIR)
	$(CC) $(DBG) -O0 $(WARNS) -c $(SRC) -o $(OUT) $(INC)

release:
	$(MKDIR)
	$(CC) $(DBG) -O3 $(WARNS) -c $(SRC) -o $(OUT) $(INC)

clean:
	rm -drf output