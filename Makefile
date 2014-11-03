SOURCES=Parser/Lexer.cpp ajs.cpp
SOURCE_DIRS=Parser
SOURCE_LINKS=Parser
OUTPUT=Binaries/ajs

all:
	g++ $(SOURCES)  -L $(SOURCE_DIRS) -I $(SOURCE_LINKS) -o $(OUTPUT)
