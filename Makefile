MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
PROJECT_DIR := $(dir $(MAKEFILE_PATH))
SOURCE_FILES = src/engine/AudioClip.cpp src/engine/AudioSystem.cpp src/engine/Engine.cpp src/engine/EventSystem.cpp src/GameScene.cpp src/GameUtility.cpp src/engine/Logger.cpp src/MainMenuScene.cpp src/engine/Mouse.cpp src/engine/RenderSystem.cpp src/engine/ResourceManager.cpp src/engine/Scene.cpp src/engine/SceneSystem.cpp src/engine/SpriteComponent.cpp src/engine/Utility.cpp src/engine/UIComponent.cpp

game: $(SOURCE_FILES)
	g++ src/Main.cpp $(SOURCE_FILES) -I /d/MinGW_Dev/include/SDL2 -L /d/MinGW_Dev/lib -I $(PROJECT_DIR)includes -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o dist/ms20 -g -std=c++17

run: game
	./dist/ms20.exe

test: 
	g++ test.cpp $(SOURCE_FILES) -I /d/MinGW_Dev/include/SDL2 -L /d/MinGW_Dev/lib -I $(PROJECT_DIR)includes -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o dist/test -g -std=c++17