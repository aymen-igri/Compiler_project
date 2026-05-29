# Makefile for Atlas Compiler

CC = gcc
CFLAGS = -lm -DAVEC_BISON
LEX = flex
YACC = bison
YFLAGS = -d

all: atlas

atlas: atlas.tab.c lex.yy.c
	$(CC) -o atlas atlas.tab.c lex.yy.c $(CFLAGS)

atlas.tab.c atlas.tab.h: atlas.y
	$(YACC) $(YFLAGS) atlas.y

lex.yy.c: atlas.l atlas.tab.h
	$(LEX) atlas.l

# Default file if none is specified
FILE = test_complet.atlas

# Target to compile a specific Atlas file
compile: atlas
	./atlas $(FILE) > final.c
	$(CC) final.c -o result

# Target to show the generated MAP code (intermediate code)
map: atlas
	@echo "--- Intermediate MAP Code for $(FILE) ---"
	./atlas $(FILE)
	@echo "----------------------------------------"

# Target to compile and run immediately
run: compile
	./result

# Target for quick verification (shows MAP then Runs)
test: map compile
	@echo "--- Execution Result ---"
	./result
	@echo "------------------------"

clean:
	rm -f atlas atlas.tab.c atlas.tab.h lex.yy.c final.c result out.c lex_test
	rm -f *.o

.PHONY: all clean test
