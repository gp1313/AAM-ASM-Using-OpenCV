CC = g++
EXE = ModelingExe

OPENCV = /usr/local/include/

MInc = ../Modules/Modeling/Inc
MSrc = ../Modules/Modeling/Src

UInc = ../Utility
USrc = ../Utility

APISrc = ../API

CFLAGS = -I $(MInc) -I $(UInc) -I $(OPENCV)

CLIBS = -L /usr/local/lib/ `pkg-config --cflags opencv` -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio

DIR_OBJ = ./obj_files

OBJ_LIST = $(DIR_OBJ)/test.o \
	   $(DIR_OBJ)/utility.o \

all : $(EXE) $(DIR_OBJ) 

$(DIR_OBJ) :
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o : $(MSrc)/%.cpp $(MInc)
	$(CC) -c -o $@ $< $(CFLAGS)

$(DIR_OBJ)/%.o : $(USrc)/%.cpp $(UInc)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE) : $(OBJ_LIST) $(APISrc)/main.cpp
	$(CC) $(OBJ_LIST) $(APISrc)/main.cpp -o $(EXE) $(CFLAGS) $(CLIBS)

clean :
	rm $(DIR_OBJ)/*.o $(EXE)
