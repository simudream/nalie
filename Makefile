SOURCES=Parser/Lexer.cpp Binaries/ajs.cpp
SOURCE_DIRS=Parser
SOURCE_LINKS=Parser
OUTPUT=ajs

all:
	g++ $(SOURCES)  -L $(SOURCE_DIRS) -I $(SOURCE_LINKS) -o $(OUTPUT)
