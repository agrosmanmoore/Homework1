# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Archivos fuente
SRC1 = ej1.cpp
SRC2 = ej2.cpp
SRC3 = ej3.cpp
SRC4 = ej4.cpp

# Ejecutables
BIN1 = ej1
BIN2 = ej2
BIN3 = ej3
BIN4 = ej4

# Regla por defecto: compila y ejecuta todo
all: run-ej1 run-ej2 run-ej3 run-ej4

# Compilación
$(BIN2): $(SRC2)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN3): $(SRC3)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN4): $(SRC4)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN1): $(SRC1)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reglas para compilar y ejecutar

run-ej1: $(BIN1)
	@echo "------ Ejecutando ej1 ------"
	./$(BIN1)

run-ej2: $(BIN2)
	@echo "------ Ejecutando ej2 ------"
	./$(BIN2)

run-ej3: $(BIN3)
	@echo "------ Ejecutando ej3 ------"
	./$(BIN3)

run-ej4: $(BIN4)
	@echo "------ Ejecutando ej4 ------"
	./$(BIN4)

clean:
	rm -f $(BIN1) $(BIN2) $(BIN3) $(BIN4) log.txt
