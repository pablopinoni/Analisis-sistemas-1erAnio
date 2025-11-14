# Variables de Configuración
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude  # -Iinclude: busca cabeceras en la carpeta include
LDFLAGS = 
TARGET = gestor_figuras_2 # Nombre del ejecutable final
SRC_DIR = src
OBJ_DIR = obj

# Archivos fuente (todos los .cpp en el directorio src, excepto main)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
SOURCES := $(filter-out $(SRC_DIR)/main.cpp, $(SOURCES))
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# El archivo objeto del main
MAIN_OBJ = $(OBJ_DIR)/main.o

# Objetivo principal: Construir el ejecutable
$(TARGET): $(MAIN_OBJ) $(OBJECTS)
	@echo "Enlazando el ejecutable..."
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "✅ Compilación y Enlazado Finalizado."

# Regla para compilar los archivos fuente (.cpp a .o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR) # Crea el directorio obj si no existe
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el main.cpp
$(MAIN_OBJ): $(SRC_DIR)/main.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar: Elimina el ejecutable y todos los archivos objeto
clean:
	@echo "Limpiando archivos objeto y ejecutable..."
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rmdir $(OBJ_DIR) 2>/dev/null || true

# Ejecutar: Depende del objetivo principal
run: $(TARGET)
	@echo ""
	@./$(TARGET)

.PHONY: all clean run