CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

TARGET = test

SRC = main.cc


all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<


.PHONY: all clean



clean:
	rm -f $(TARGET)