MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
PROJECT_DIR := $(dir $(MAKEFILE_PATH))
CPP_FILES := $(shell find src/ -type f -name '*.cpp')
CPP_FILENAMES := $(patsubst src/%.cpp,%,$(CPP_FILES))

define COMPILE_CPP

build/$(1).o : src/$(1).cpp
	@g++ -c src/$(1).cpp -I $(PROJECT_DIR)includes -I /d/MinGW_Dev/include/SDL2 -o build/$(1).o -O0 -std=c++17 -g

endef

$(foreach file, $(CPP_FILENAMES), $(eval $(call COMPILE_CPP,$(file))))

dist/ms20: $(foreach file, $(CPP_FILENAMES), build/$(file).o)
	@g++ $(foreach file, $(CPP_FILENAMES), build/$(file).o) -L /d/MinGW_Dev/lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o dist/ms20

# release: FORCE
# 	@g++ $(foreach file, $(CPP_FILENAMES), build/$(file).o) -L /d/MinGW_Dev/lib -L/opt/local/i686-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2 -mwindows -Wl,--no-undefined -Wl,--dynamicbase -Wl,--nxcompat -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid -static-libgcc -o release/ms20 -static

# FORCE:

run: dist/ms20
	./dist/ms20.exe