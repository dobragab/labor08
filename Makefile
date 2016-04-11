BINARY = labor08

SRCDIR   = src
OBJDIR   = obj
BINDIR   = .

RM       = rm -f
MAKEDIR  = mkdir -p

WARNINGS = -Wall -Wdeprecated -pedantic -Wfloat-equal -Wunreachable-code -Wnon-virtual-dtor

SDL_CONFIG = `sdl-config --cflags` -I.

SDL_LIBS = `sdl-config --libs` -lSDL_gfx -lSDL_ttf -lSDL_image -lSDL_mixer


CC = gcc
CFLAGS = -std=c99 -O3 $(WARNINGS) $(SDL_CONFIG)

CXX = g++
CXXFLAGS = -std=c++11 -O3 $(WARNINGS) $(SDL_CONFIG) -pthread
LDFLAGS = $(SDL_LIBS) -lm -lz

HEADERS := $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/*.hpp) $(wildcard $(SRCDIR)/*.hh) $(wildcard $(SRCDIR)/*.hxx)

SOURCES_C   := $(wildcard $(SRCDIR)/*.c)
SOURCES_CPP := $(wildcard $(SRCDIR)/*.cpp)
SOURCES_CC  := $(wildcard $(SRCDIR)/*.cc)
SOURCES_CXX := $(wildcard $(SRCDIR)/*.cxx)

SOURCES = $(SOURCES_C) $(SOURCES_CPP) $(SOURCES_CC) $(SOURCES_CXX)

OBJECTS_C   := $(SOURCES_C:$(SRCDIR)/%.c=$(OBJDIR)/%.c.o)
OBJECTS_CPP := $(SOURCES_CPP:$(SRCDIR)/%.cpp=$(OBJDIR)/%.cpp.o)
OBJECTS_CC  := $(SOURCES_CC:$(SRCDIR)/%.cc=$(OBJDIR)/%.cc.o)
OBJECTS_CXX := $(SOURCES_CXX:$(SRCDIR)/%.cxx=$(OBJDIR)/%.cxx.o)

OBJECTS = $(OBJECTS_C) $(OBJECTS_CPP) $(OBJECTS_CC) $(OBJECTS_CXX)

.PHONY: clean all dirs Linux LinuxDebug

all: dirs $(BINDIR)/$(BINARY)

Linux: all

LinuxDebug: all
LinuxDebug: CFLAGS += -DDEBUG -g -O0
LinuxDebug: CXXFLAGS += -DDEBUG -g -O0
LinuxDebug: LDFLAGS += -g

clean:
	@$(RM) $(OBJDIR)/*.o
	@$(RM) $(BINDIR)/$(BINARY)
	@echo Cleaned successfully.

dirs:
	@$(MAKEDIR) $(BINDIR)
	@$(MAKEDIR) $(OBJDIR)

$(BINDIR)/$(BINARY): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJDIR)/%.c.o : $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.cpp.o : $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.cc.o : $(SRCDIR)/%.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.cxx.o : $(SRCDIR)/%.cxx $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
