CC = g++
CFLAGS = -c -Wall
SOURCES = main.cpp geometry.cpp parse.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = geo

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
