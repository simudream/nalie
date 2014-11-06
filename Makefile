SOURCES=Parser/Lexer.cpp Binaries/ajs.cpp
SOURCE_DIRS=Parser
SOURCE_LINKS=Parser
OUTPUT=ajs

all:
	g++ $(SOURCES)  -L $(SOURCE_DIRS) -I $(SOURCE_LINKS) -o $(OUTPUT)

test:
	g++ Specifications/TestRunner.cpp Specifications/spec.cpp -I Includes/igloo -o Specifications/test
	./Specifications/test

get-deps:
	git submodule update --recursive

.PHONY: test