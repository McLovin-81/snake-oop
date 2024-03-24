SOURCE = main.cpp
LIBRARY = raylib
EXECUTABLE = $(basename $(SOURCE)) # Executable name drived from source file without extension 
CXX = g++

# (-I) This flag adds the specified directory to the list of directories to be searched for header files during compilation
CXXFLAGS = -std=c++20 -I/opt/homebrew/Cellar/$(LIBRARY)/5.0/include

# (-L) This flag adds the specified directory to the list of directories to be searched for libraries during linking.
# (-l) This flag tells the linker to link against the specified library.
# (-lpthread) This flag links the program with the pthread library, which is used for multi-threading support.
LDFLAGS = -L/opt/homebrew/Cellar/$(LIBRARY)/5.0/lib -l$(LIBRARY) -lpthread

# Default target: build the executable
all: $(EXECUTABLE)

# Rule to build the executable from source file
$(EXECUTABLE): $(SOURCE)
	@echo "Compiling..."
	@$(CXX) $(SOURCE) -o $(EXECUTABLE) $(CXXFLAGS) $(LDFLAGS)

# Run the executable
run:
	@./$(EXECUTABLE)

clean:
	@echo "Cleaning..."
	@rm -f $(EXECUTABLE)


# Old command: g++ -o main main.cpp -lraylib -I/opt/homebrew/Cellar/raylib/5.0/include -L/opt/homebrew/Cellar/raylib/5.0/lib -lpthread -std=c++20