# a sample Makefile

CC = clang++
CFLAGS = -g -Wall 
LDFLAGS = -lSDL2 -lGL -lpng -L/usr/local/include

ifeq ($(UNAME_S),Darwin)
    LDFLAGS += -framework OpenGL -framework SDL2
endif

PROG = JACE 
HDRS = 	Game.h \
	JACE_Common.h \
	ContentHandler/ContentHandler.h \
	ContentHandler/Texture2D.h \
	ContentHandler/Textures/PNGTex.h \
	EventEngine/EventSystem.h \
	EventEngine/Keyboard.h \
	EventEngine/Mouse.h \
	GraphicsEngine/GraphicsEngine.h \
	GraphicsEngine/Rectangle.h \
	GraphicsEngine/Renderer.h \
	GraphicsEngine/Window.h
SRCS = 	main.cpp \
	Game.cpp \
	ContentHandler/ContentHandler.cpp \
	ContentHandler/Texture2D.cpp \
	ContentHandler/Textures/PNGTex.cpp \
	EventEngine/EventSystem.cpp \
	EventEngine/Keyboard.cpp \
	EventEngine/Mouse.cpp \
	GraphicsEngine/GraphicsEngine.cpp \
	GraphicsEngine/Rectangle.cpp \
	GraphicsEngine/Renderer.cpp \
	GraphicsEngine/Window.cpp

OBJS = 	obj/main.o \
	obj/Game.o \
	obj/ContentHandler/ContentHandler.o \
	obj/ContentHandler/Texture2D.o \
	obj/ContentHandler/Textures/PNGTex.o \
	obj/EventEngine/EventSystem.o \
	obj/EventEngine/Keyboard.o \
	obj/EventEngine/Mouse.o \
	obj/GraphicsEngine/GraphicsEngine.o \
	obj/GraphicsEngine/Rectangle.o \
	obj/GraphicsEngine/Renderer.o \
	obj/GraphicsEngine/Window.o 

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(PROG)

obj/main.o: main.cpp $(HDRS)
	$(CC) $(CFLAGS) -c main.cpp -o obj/main.o

obj/Game.o: Game.cpp $(HDRS)
	$(CC) $(CFLAGS) -c Game.cpp -o obj/Game.o

obj/ContentHandler/ContentHandler.o: ContentHandler/ContentHandler.cpp $(HDRS)
	$(CC) $(CFLAGS) -c ContentHandler/ContentHandler.cpp -o obj/ContentHandler/ContentHandler.o

obj/ContentHandler/Texture2D.o: ContentHandler/Texture2D.cpp $(HDRS)
	$(CC) $(CFLAGS) -c ContentHandler/Texture2D.cpp -o obj/ContentHandler/Texture2D.o

obj/ContentHandler/Textures/PNGTex.o: ContentHandler/Textures/PNGTex.cpp $(HDRS)
	$(CC) $(CFLAGS) -c ContentHandler/Textures/PNGTex.cpp -o obj/ContentHandler/Textures/PNGTex.o

obj/EventEngine/EventSystem.o: EventEngine/EventSystem.cpp $(HDRS)
	$(CC) $(CFLAGS) -c EventEngine/EventSystem.cpp -o obj/EventEngine/EventSystem.o

obj/EventEngine/Keyboard.o: EventEngine/Keyboard.cpp $(HDRS)
	$(CC) $(CFLAGS) -c EventEngine/Keyboard.cpp -o obj/EventEngine/Keyboard.o

obj/EventEngine/Mouse.o: EventEngine/Mouse.cpp $(HDRS)
	$(CC) $(CFLAGS) -c EventEngine/Mouse.cpp -o obj/EventEngine/Mouse.o

obj/GraphicsEngine/GraphicsEngine.o: GraphicsEngine/GraphicsEngine.cpp $(HDRS)
	$(CC) $(CFLAGS) -c GraphicsEngine/GraphicsEngine.cpp -o obj/GraphicsEngine/GraphicsEngine.o

obj/GraphicsEngine/Rectangle.o: GraphicsEngine/Rectangle.cpp $(HDRS)
	$(CC) $(CFLAGS) -c GraphicsEngine/Rectangle.cpp -o obj/GraphicsEngine/Rectangle.o

obj/GraphicsEngine/Renderer.o: GraphicsEngine/Renderer.cpp $(HDRS)
	$(CC) $(CFLAGS) -c GraphicsEngine/Renderer.cpp -o obj/GraphicsEngine/Renderer.o

obj/GraphicsEngine/Window.o: GraphicsEngine/Window.cpp $(HDRS)
	$(CC) $(CFLAGS) -c GraphicsEngine/Window.cpp -o obj/GraphicsEngine/Window.o

clean:
	rm -f $(PROG) $(OBJS)



