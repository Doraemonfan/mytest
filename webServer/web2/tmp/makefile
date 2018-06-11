SOURCE := $(wildcard *.c)
OBJ := $(SOURCE:.c=.o)

$(OBJ): %: %.c
	gcc -c $<
