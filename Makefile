# inspirited by https://gitlab.fit.cvut.cz/husekrad/pa2-cvika-2022/blob/70cface336f6fc3ece18978d05797eacef9dbf55/cv10/semestralka/Makefile
# and https://gitlab.fit.cvut.cz/bernhdav/pa2-bomb-tag/blob/master/Makefile

TARGET = hejnitad

CXX = g++
CXX_FLAGS = -std=c++17 -Wall -pedantic
LDLIBS = -lstdc++fs

HEADERS = $( ls src/*/*.h )
MKDIR= mkdir -p
BUILD_DIR = build

.PHONY: all compile run valgrind doc clean count

all: compile #doc
	@echo "Finished..."

compile: $(TARGET)
	@echo "Compiled..."


$(TARGET): 	$(BUILD_DIR)/main.o $(BUILD_DIR)/CApplication.o $(BUILD_DIR)/CMenu.o \
			$(BUILD_DIR)/CBoardGenerator.o $(BUILD_DIR)/CBoardLoader.o \
			$(BUILD_DIR)/CBoardSaver.o  $(BUILD_DIR)/CBishop.o $(BUILD_DIR)/CChessman.o \
			$(BUILD_DIR)/CKing.o $(BUILD_DIR)/CKnight.o $(BUILD_DIR)/CPawn.o \
			$(BUILD_DIR)/CQueen.o $(BUILD_DIR)/CRook.o $(BUILD_DIR)/CBoard.o \
			$(BUILD_DIR)/CField.o $(BUILD_DIR)/CGame.o $(BUILD_DIR)/CRules.o \
			$(BUILD_DIR)/CBeginner.o $(BUILD_DIR)/CHuman.o $(BUILD_DIR)/CLegend.o \
			$(BUILD_DIR)/CPlayer.o $(BUILD_DIR)/CPro.o $(BUILD_DIR)/CMove.o
	$(CXX) $(CXX_FLAGS) $^ -o $@ #$(LDLIBS)

$(BUILD_DIR)/%.o: 	src/*/%.cpp
	$(MKDIR) $(BUILD_DIR)
	$(CXX) $(CXX_FLAGS) $< -c -o $@


run: $(TARGET)
	./$(TARGET)

valgrind: compile
	valgrind ./$(TARGET)

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile

count:
	wc -l src/*/*

clean:
	rm -rf $(TARGET) $(BUILD_DIR)/ doc/ 2>/dev/null

# DEPENDENCIES
$(BUILD_DIR)/main.o: src/Main/main.cpp src/Application/CApplication.h
$(BUILD_DIR)/CApplication.o: src/Application/CApplication.cpp \
  src/Application/CApplication.h src/Application/CMenu.h \
  src/Game/CGame.h \
  src/Player/CPlayer.h \
  src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h
$(BUILD_DIR)/CMenu.o: src/Application/CMenu.cpp src/Application/CMenu.h \
  src/Application/EState.h src/Application/Constants.h
$(BUILD_DIR)/CBoardGenerator.o: src/Builders/CBoardGenerator.cpp \
  src/Builders/CBoardGenerator.h src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Chessman/CBishop.h \
  src/Chessman/CChessman.h \
  src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h \
  src/Chessman/CKing.h src/Chessman/CKnight.h \
  src/Chessman/CPawn.h src/Chessman/CQueen.h \
  src/Chessman/CRook.h
$(BUILD_DIR)/CBoardLoader.o: src/Builders/CBoardLoader.cpp src/Builders/CBoardLoader.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/CMenu.h \
  src/Chessman/CChessman.h \
  src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h \
  src/Chessman/CRook.h src/Chessman/CKnight.h \
  src/Chessman/CBishop.h src/Chessman/CQueen.h \
  src/Chessman/CKing.h
$(BUILD_DIR)/CBoardSaver.o: src/Builders/CBoardSaver.cpp src/Builders/CBoardSaver.h \
  src/Game/CBoard.h src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h
$(BUILD_DIR)/CBishop.o: src/Chessman/CBishop.cpp src/Chessman/CBishop.h \
  src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h src/Game/CRules.h
$(BUILD_DIR)/CChessman.o: src/Chessman/CChessman.cpp src/Chessman/CChessman.h \
  src/Game/CBoard.h src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h
$(BUILD_DIR)/CKing.o: src/Chessman/CKing.cpp src/Chessman/CKing.h \
  src/Chessman/CChessman.h src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h src/Game/CRules.h
$(BUILD_DIR)/CKnight.o: src/Chessman/CKnight.cpp src/Chessman/CKnight.h \
  src/Chessman/CChessman.h src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h src/Game/CRules.h
$(BUILD_DIR)/CPawn.o: src/Chessman/CPawn.cpp src/Chessman/CPawn.h \
  src/Chessman/CChessman.h src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h src/Game/CRules.h
$(BUILD_DIR)/CQueen.o: src/Chessman/CQueen.cpp src/Chessman/CQueen.h \
  src/Chessman/CChessman.h src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h src/Game/CRules.h
$(BUILD_DIR)/CRook.o: src/Chessman/CRook.cpp src/Chessman/CRook.h \
  src/Chessman/CChessman.h src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h src/Game/CRules.h
$(BUILD_DIR)/CBoard.o: src/Game/CBoard.cpp src/Game/CBoard.h src/Game/CField.h \
  src/Application/EState.h src/Application/Constants.h \
  src/Builders/CBoardLoader.h \
  src/Game/CField.h \
  src/Builders/CBoardGenerator.h \
  src/Chessman/CChessman.h src/Game/CBoard.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h
$(BUILD_DIR)/CField.o: src/Game/CField.cpp src/Game/CField.h \
  src/Application/EState.h src/Builders/CBoardSaver.h \
  src/Game/CBoard.h src/Game/CField.h \
  src/Application/Constants.h src/Chessman/CQueen.h \
  src/Chessman/CChessman.h src/Game/CBoard.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h \
  src/Chessman/CRook.h src/Chessman/CBishop.h \
  src/Chessman/CKnight.h
$(BUILD_DIR)/CGame.o: src/Game/CGame.cpp src/Game/CGame.h src/Player/CPlayer.h \
  src/Game/CBoard.h src/Game/CField.h \
  src/Application/EState.h src/Application/Constants.h \
  src/Player/CHuman.h src/Player/CBeginner.h \
  src/Player/CPro.h src/Player/CLegend.h \
  src/Game/CRules.h \
  src/Game/CBoard.h
$(BUILD_DIR)/CRules.o: src/Game/CRules.cpp src/Game/CRules.h src/Game/CBoard.h \
  src/Game/CField.h src/Application/EState.h \
  src/Application/Constants.h src/Chessman/CChessman.h \
  src/Game/CBoard.h \
  src/Application/EState.h \
  src/Application/Constants.h
$(BUILD_DIR)/CMove.o: src/Move/CMove.cpp src/Move/CMove.h src/Game/CBoard.h \
	src/Game/CField.h \
	src/Application/EState.h \
	src/Application/Constants.h \
	src/Game/CBoard.h \
	src/Application/EState.h \
	src/Application/Constants.h \
	src/Application/EDir.h src/Game/CRules.h \
	src/Chessman/CQueen.h src/Move/ranks.h
$(BUILD_DIR)/CBeginner.o: src/Player/CBeginner.cpp src/Player/CBeginner.h \
  src/Player/CPlayer.h src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Chessman/CChessman.h \
  src/Game/CBoard.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h \
  src/Game/CRules.h
$(BUILD_DIR)/CHuman.o: src/Player/CHuman.cpp src/Player/CHuman.h src/Player/CPlayer.h \
  src/Game/CBoard.h src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Chessman/CChessman.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Application/EDir.h \
  src/Game/CRules.h src/Builders/CBoardSaver.h
$(BUILD_DIR)/CLegend.o: src/Player/CLegend.cpp src/Player/CLegend.h \
  src/Player/CPlayer.h src/Game/CBoard.h \
  src/Game/CField.h \
  src/Application/Constants.h \
  src/Move/CMove.h \
  src/Chessman/CChessman.h \
  src/Application/EState.h \
  src/Application/EDir.h \
  src/Game/CRules.h
$(BUILD_DIR)/CPlayer.o: src/Player/CPlayer.cpp src/Player/CPlayer.h \
  src/Game/CBoard.h src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Chessman/CChessman.h \
  src/Application/EDir.h
$(BUILD_DIR)/CPro.o: src/Player/CPro.cpp src/Player/CPro.h src/Player/CPlayer.h \
  src/Game/CBoard.h src/Game/CField.h \
  src/Application/EState.h \
  src/Application/Constants.h \
  src/Game/CRules.h src/Chessman/CChessman.h \
  src/Application/EState.h \
  src/Application/EDir.h



