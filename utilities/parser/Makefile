CXX=g++
CXXFLAGS=-Wall -O3
EXE=parser
INC_DIR=../../app
SRC_DIR=../../app
# PARSER_SRC=../../app/buffer.cpp ../../app/cli.cpp ../../app/packet.cpp ../../app/parser.cpp ../../app/utility.cpp
SRC_NAMES=buffer.cpp cli.cpp packet.cpp parser.cpp utility.cpp
PARSER_SRC=$(addprefix $(SRC_DIR)/, $(SRC_NAMES))

all:
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -o $(EXE) $(PARSER_SRC)

clean:
	$(RM) $(EXE)
