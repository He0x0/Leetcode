CXX = g++

TARGET = test
CXXFLAGS = -Wall -std=c++11 -g
SRC = main.cc
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<


clean:
	rm -f $(TARGET)


.PHONY: all clean