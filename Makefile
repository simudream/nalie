SOURCES = $(wildcard Parser/*.cpp Binaries/*.cpp)
SOURCE_DIRS=Parser
SOURCE_LINKS=Parser
SPECIFICATION_FILES = Specifications/TestRunner.cpp $(wildcard Parser/*.cpp)
OPTIONS = -std=c++11
OUTPUT=ajs

all:
	clang++ $(SOURCES) -I $(SOURCE_LINKS) $(OPTIONS) -o $(OUTPUT)

test:
	clang++ $(SPECIFICATION_FILES) -I Includes/igloo -o Specifications/test
	./Specifications/test

get-deps:
	git submodule update --recursive
