executbale := complicated
sources := $(wildcard *.c)
objects := $(sources:.c=.o)

CC := gcc
RM := rm -rf

$(executbale): $(objects)
	$(CC) -o $@ $^

$(objects):%.o: %.c
	$(CC) -o $@ -c $<

$(objects): complicated.h

.PHONY: clean

clean: 
	$(RM) $(objects) $(executbale)
