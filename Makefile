GCC = "g++"
BULD_DIR="build"
TARGET="test2gis"
SRC="./src"
GDB="gdb"

$(TARGET): mkbdir
	$(GCC) -std=c++1z $(SRC)/main.cpp -o ./$(BULD_DIR)/$(TARGET)

mkbdir:
	mkdir -p $(BULD_DIR)

test: $(TARGET)
	./$(BULD_DIR)/$(TARGET)

debug: $(TARGET)
	$(GDB) ./$(BULD_DIR)/$(TARGET)
