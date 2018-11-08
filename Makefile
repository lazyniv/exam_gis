GCC = "g++"
BULD_DIR = "build"
TARGET = "test2gis"
SRC = "./src"
LIB = "lib"
COMMAND = "Command"
HASH = "Hash"
COUNTER = "Counter"
FILE_ANALYZER = "FileAnalyzer"
HELP = "Help"
CliPARSER = "CliParser"
GDB = "gdb"
WORD = "world"

$(TARGET): mkbdir
	$(GCC) -std=c++1z $(SRC)/$(LIB)/$(FILE_ANALYZER)/FileAnalyzer.cpp \
$(SRC)/$(LIB)/$(COUNTER)/Counter.cpp \
$(SRC)/$(LIB)/$(HASH)/Hash.cpp \
$(SRC)/$(LIB)/$(COMMAND)/Command.cpp \
$(SRC)/$(LIB)/$(HELP)/Help.cpp \
$(SRC)/$(LIB)/$(CliPARSER)/CliParser.cpp \
$(SRC)/main.cpp -o ./$(BULD_DIR)/$(TARGET)


mkbdir:
	mkdir -p $(BULD_DIR)

test_hash: $(TARGET)
	./$(BULD_DIR)/$(TARGET) -f test/fixtures/input.bin -m checksum
test_counter: $(TARGET)
	./$(BULD_DIR)/$(TARGET) -f test/fixtures/input.txt -m words -v $(WORD)
test_help: $(TARGET)
	./$(BULD_DIR)/$(TARGET) -h
test_error: $(TARGET)
	./$(BULD_DIR)/$(TARGET) -f ewfewfwe
debug: $(TARGET)
	$(GDB) ./$(BULD_DIR)/$(TARGET)
