CC = gcc
CFLAGS = -lm -DAVEC_BISON
LEX = flex
YACC = bison
YFLAGS = -d

all: atlas map_interpreter

atlas: atlas.tab.c lex.yy.c main.c
	$(CC) -o atlas main.c atlas.tab.c lex.yy.c $(CFLAGS)

atlas.tab.c atlas.tab.h: atlas.y
	$(YACC) $(YFLAGS) atlas.y

lex.yy.c: atlas.l atlas.tab.h
	$(LEX) atlas.l

map_interpreter: map_interpreter.c simulator.c
	$(CC) -o map_interpreter map_interpreter.c $(CFLAGS)

# Compile Atlas to MAP and execute
run: atlas map_interpreter
	./atlas $(FILE)
	./map_interpreter $(basename $(FILE)).map

# Show MAP code
map: atlas
	./atlas $(FILE)
	@echo "--- Generated MAP Code ---"
	@cat $(basename $(FILE)).map
	@echo "------------------------"

clean:
	rm -f atlas atlas.tab.c atlas.tab.h lex.yy.c map_interpreter
	rm -f *.map
	rm -f *.o

.PHONY: all clean run map