#CXX      =  clang++
CXX       =  gcc
CXXFLAGS  = -Iinclude -std=c11
LDFLAGS   = -lraylib -lm -lpthread
BIN       = -o bin/app
OBJ       = obj
OBJS       = $(patsubst src/%.c, obj/%.o, $(wildcard src/*.c))

obj/%.o: src/%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CXX) $(CXXFLAGS) main.c -E $^ $(BIN) $(LDFLAGS)

preprocessor: $(OBJS)
	$(CXX) $(CXXFLAGS) -E main.c $^ $(BIN) $(LDFLAGS)

debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -ggdb main.c $^ $(BIN) $(LDFLAGS)

release: CXXFLAGS= -Iinclude -Wall -O3 -DNDEBUG
release: all

clean:
	rm obj/*
	rm bin/*

