executbale := complicated
sources := $(wildcard *.c)
objects := $(sources:.c=.o)

deps := $(sources:.c=.d)

CC := gcc
RM := rm -rf

$(executbale): $(objects)
	$(CC) -o $@ $^
$(objects):%.o: %.c
	$(CC) -o $@ -c $<
.PHONY: clean
clean:
	$(RM) $(executbale) $(objects) $(deps)

sinclude $(deps)
$(deps):%.d:%.c
	  $(CC) -MM $< > $@
