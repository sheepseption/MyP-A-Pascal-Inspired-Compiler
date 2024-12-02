# Compiler and flags
CC = gcc
CFLAGS =  -g -I src

# Directories
SRC_DIR = src
PCODE_DIR = $(SRC_DIR)/PCode

# Files
LEX_FILE = $(SRC_DIR)/myp.l
YACC_FILE = $(SRC_DIR)/myp.y
SYM_TABLE = $(SRC_DIR)/Table_des_symboles.c
CHAIN_TABLE = $(SRC_DIR)/Table_des_chaines.c
PCODE_SRC = $(PCODE_DIR)/PCode.c
PCODE_OBJ = $(PCODE_DIR)/PCode.o
LEX_OUTPUT = lex.yy.c
YACC_OUTPUT = y.tab.c
YACC_HEADER = y.tab.h
OUTPUT_BINARY = myp

# Targets
all: $(OUTPUT_BINARY)

# Main binary compilation
$(OUTPUT_BINARY): $(YACC_OUTPUT) $(LEX_OUTPUT) $(SYM_TABLE) $(CHAIN_TABLE) $(PCODE_OBJ)
	$(CC) $(CFLAGS) -o $@ $(YACC_OUTPUT) $(LEX_OUTPUT) $(SYM_TABLE) $(CHAIN_TABLE) $(PCODE_OBJ)

# Generate syntax parser with Bison
$(YACC_OUTPUT) $(YACC_HEADER): $(YACC_FILE)
	bison -v -y -d $<

# Generate lexer with Flex
$(LEX_OUTPUT): $(LEX_FILE)
	flex $<

# Compile PCode object
$(PCODE_OBJ): $(PCODE_SRC) $(PCODE_DIR)/PCode.h
	$(MAKE) -C $(PCODE_DIR) pcode

# Clean up
clean:
	rm -f $(LEX_OUTPUT) $(YACC_OUTPUT) $(YACC_HEADER) $(OUTPUT_BINARY) *~ y.output
	$(MAKE) -C $(PCODE_DIR) clean
