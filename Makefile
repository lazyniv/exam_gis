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
PARSER = "Parser"
GDB = "gdb"

$(TARGET): mkbdir
	$(GCC) -std=c++1z $(SRC)/$(LIB)/$(FILE_ANALYZER)/FileAnalyzer.cpp \
$(SRC)/$(LIB)/$(COUNTER)/Counter.cpp \
$(SRC)/$(LIB)/$(HASH)/Hash.cpp \
$(SRC)/$(LIB)/$(COMMAND)/Command.cpp \
$(SRC)/$(LIB)/$(HELP)/Help.cpp \
$(SRC)/$(LIB)/$(PARSER)/Parser.cpp \
$(SRC)/main.cpp -o ./$(BULD_DIR)/$(TARGET)


mkbdir:
	mkdir -p $(BULD_DIR)

test: $(TARGET)
	./$(BULD_DIR)/$(TARGET)

debug: $(TARGET)
	$(GDB) ./$(BULD_DIR)/$(TARGET)
