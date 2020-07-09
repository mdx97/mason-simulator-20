SOURCE_FILES = src/AudioClip.cpp src/AudioSystem.cpp src/Button.cpp src/EventSystem.cpp src/Main.cpp src/MainMenuScene.cpp src/Mouse.cpp src/PlayButton.cpp src/RenderSystem.cpp src/Scene.cpp src/SceneSystem.cpp src/SDLUtility.cpp src/Window.cpp

game: $(SOURCE_FILES)
	g++ $(SOURCE_FILES) -I /d/MinGW_Dev/include/SDL2 -L /d/MinGW_Dev/lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o dist/ms20 -g

run: game
	./dist/ms20.exe