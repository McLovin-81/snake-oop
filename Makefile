SOURCE = main.cpp

LIBRARY = ncurses

TARGET = $(SOURCE:.cpp=)

CXX = g++

CXXFLAGS = -std=c++17

all: $(TARGET)
$(TARGET): $(SOURCE)
	@echo "Commpiling..."
	@$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET) -l $(LIBRARY)

run:
	@./$(TARGET)

clean:
	@echo "Cleaning.."
	@rm $(TARGET)

.PHONY: all run clean
