SOURCES = $(wildcard Parser/*.cpp Binaries/*.cpp)
SOURCE_DIRS=Parser
SOURCE_LINKS=Parser
SPECIFICATION_FILES = Specifications/TestRunner.cpp $(wildcard Parser/*.cpp)
OUTPUT=ajs

all:
	llvm-g++ $(SOURCES)  -L $(SOURCE_DIRS) -I $(SOURCE_LINKS) $(OPTIONS) -o $(OUTPUT)

test:
	llvm-g++ $(SPECIFICATION_FILES) -I Includes/igloo -o Specifications/test
	./Specifications/test

get-deps:
	git submodule update --recursive

.PHONY: test