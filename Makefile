GCC = "g++"
BULD_DIR = "build"
TARGET = "test"
SRC = "./src"
LIB = "lib"
COMMAND = "Command"
HASH = "Hash"
COUNTER = "Counter"
FILE_ANALYZER = "FileAnalyzer"
HELP = "Help"
CliDEFINITION = "CliDefinition"
GDB = "gdb"
WORD = "world"

$(TARGET): mkbdir
	$(GCC) -std=c++1z $(SRC)/$(LIB)/$(FILE_ANALYZER)/FileAnalyzer.cpp \
$(SRC)/$(LIB)/$(COUNTER)/Counter.cpp \
$(SRC)/$(LIB)/$(HASH)/Hash.cpp \
$(SRC)/$(LIB)/$(COMMAND)/Command.cpp \
$(SRC)/$(LIB)/$(CliDEFINITION)/CliDefinition.cpp \
$(SRC)/$(LIB)/$(HELP)/Help.cpp \
$(SRC)/main.cpp -o ./$(BULD_DIR)/$(TARGET)


mkbdir:
	mkdir -p $(BULD_DIR)
