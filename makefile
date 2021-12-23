CC         = g++
BASE_FLAGS = -std=c++17
SOURCES    = $(wildcard *.cpp) $(wildcard **/*.cpp)
OBJECTS    = ${SOURCES:%.cpp=%.o}
EXEC       = leetcode.exe

release: TARGET_FLAGS = -O3
debug: TARGET_FLAGS = -g -Wall -O0 -W -pedantic-errors

release: EXEC = leetcode.rel.exe
debug: EXEC = leetcode.dbg.exe
leakcheck: EXEC = leetcode.dbg.exe
callgrind: EXEC = leetcode.dbg.exe
clean: EXEC = leetcode.rel.exe leetcode.dbg.exe

default: release
all: clean release run

%.o: %.cpp
	$(CC) $(BASE_FLAGS) -c $< -o $@

release: $(OBJECTS)
	$(CC) $(BASE_FLAGS) $(OBJECTS) -o $(EXEC)

debug: $(OBJECTS)
	$(CC) $(BASE_FLAGS) $(OBJECTS) -o $(EXEC)

leakcheck: debug
	valgrind --leak-check=full ./$(EXEC)

callgrind: debug
	valgrind --tool=callgrind ./$(EXEC)

run: release
	./$(EXEC)

clean:
	-@rm -f $(OBJECTS) >/dev/null 2>&1
	-@rm -f $(EXEC) >/dev/null 2>&1
