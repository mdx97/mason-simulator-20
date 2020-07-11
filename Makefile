MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
PROJECT_DIR := $(dir $(MAKEFILE_PATH))
SOURCE_FILES = src/engine/AudioClip.cpp src/engine/AudioSystem.cpp src/engine/Button.cpp src/engine/Engine.cpp src/engine/EventSystem.cpp src/Main.cpp src/MainMenuScene.cpp src/engine/Mouse.cpp src/PlayButton.cpp src/engine/RenderSystem.cpp src/engine/Scene.cpp src/engine/SceneSystem.cpp

game: $(SOURCE_FILES)
	g++ $(SOURCE_FILES) -I /d/MinGW_Dev/include/SDL2 -L /d/MinGW_Dev/lib -I $(PROJECT_DIR)includes -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o dist/ms20 -g

run: game
	./dist/ms20.exe