CC = gcc
CFLAGS = -Iincludes -lm -DAVEC_BISON
LEX = flex
YACC = bison
YFLAGS = -d

# Target directories
SRC_DIR = src
BIN_DIR = bin

all: $(BIN_DIR)/atlas

$(BIN_DIR)/atlas: $(SRC_DIR)/atlas.tab.c $(SRC_DIR)/lex.yy.c $(SRC_DIR)/main.c $(SRC_DIR)/simulator.c
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(CFLAGS)

$(SRC_DIR)/atlas.tab.c $(SRC_DIR)/atlas.tab.h: $(SRC_DIR)/atlas.y
	$(YACC) $(YFLAGS) -o $(SRC_DIR)/atlas.tab.c $<

$(SRC_DIR)/lex.yy.c: $(SRC_DIR)/atlas.l $(SRC_DIR)/atlas.tab.h
	$(LEX) -o $@ $<

# Run command (Example: make run FILE=examples/factoriel.atlas)
run: all
	./$(BIN_DIR)/atlas $(FILE)

# Show generated MAP code without executing
map: all
	@./$(BIN_DIR)/atlas $(FILE) > /dev/null
	@cat $(basename $(FILE)).map

# Full cleanup: removes all binaries and old root junk
clean:
	rm -rf $(BIN_DIR)
	rm -f $(SRC_DIR)/*.tab.c $(SRC_DIR)/*.tab.h $(SRC_DIR)/lex.yy.c
	rm -f *.map examples/*.map
	@# Remove legacy root files
	rm -f atlas atlas.tab.c atlas.tab.h lex.yy.c map_interpreter map_interpreter.c simulator.c simulator.exe out.c final.c final_test2.c atlas_lex lex_test debug_parse* test_lex* test_tokens*

.PHONY: all clean run
