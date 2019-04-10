CXX  		:= g++
CXX_FLAGS 	:= -std=c++17 -fPIC -Wall -Wextra -Werror -Wfatal-errors -Wno-unused-parameter -fdiagnostics-color -O3
LD_FLAGS 	:=

BIN		:= bin
MAIN		:= src
SRC		:= src/mtecs/**
INCLUDE		:= -Iinclude -Ilibs/utl/include
LIB		:= libs

LIBRARIES	:=
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) $(LD_FLAGS)
clean:
	-rm $(BIN)/*
