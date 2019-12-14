###############################################################################
# Project name: Project 2 - Zoo Tycoon - Makefile
# Name: Nicole Reynoldson
# Date: 7/20/19
# #############################################################################

CXX = g++
CXXFLAGS = -g -std=c++0x -Wall -pedantic-errors
OBJS = $(SRCS:.cpp=.o)
SRCS = main.cpp Zoo.cpp Animal.cpp getInput.cpp Tiger.cpp Penguin.cpp 
SRCS += Turtle.cpp menus.cpp
HEADERS = Animal.hpp Zoo.hpp Tiger.hpp getInput.hpp Penguin.hpp 
HEADERS += Turtle.hpp menus.hpp constants.hpp
TARGET = project2

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm $(OBJS) $(TARGET)

