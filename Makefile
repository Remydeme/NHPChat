CXXFLAGS=-std=c++14 -Wall -Wextra -Werror -pedantic -g3
CXX=g++
SRC= main.cpp serveur.cpp socket.cpp serveur_socket.cpp 
BIN= TCPserveur

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@
clean: 
	@rm -rf $(BIN)
