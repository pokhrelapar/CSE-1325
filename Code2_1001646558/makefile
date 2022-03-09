#Apar Pokhrel, 1001646558

SRC = Code2_1001646558.cpp
OBJ = $(SRC:.cpp=.o)
EXE = $(SRC:.cpp=.e)

HFILES = SnackMachine.h


CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ) 
	g++ $(CFLAGS) $(OBJ) -o $(EXE) 

$(OBJ) : $(SRC) $(HFILES)
	g++ -c $(CFLAGS) $(SRC) -o $(OBJ) 

	

