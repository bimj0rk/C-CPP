APP_NAME = Laboratory_2
BUILD_DIR = ./App
C_FILES = ./main.cpp

APP_DEFINES:=
APP_INCLUDES:= -I./Dependencies/GLFW  -I./Dependencies/GLEW -framework OpenGL -framework Cocoa -framework IOKit  
APP_LINKERS:= -L./Dependencies/GLFW/lib -lglfw3

build:
	clang $(C_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES) $(APP_LINKERS)