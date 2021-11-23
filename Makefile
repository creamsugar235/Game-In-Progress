all: compilegame compile run

build:
	g++ -c -Wall -std=c++17 src/geometrylib/Calc.cpp -o bin/o/Calc.o
	g++ -c -Wall -std=c++17 src/geometrylib/ConvexShape.cpp -o bin/o/ConvexShape.o
	g++ -c -Wall -std=c++17 src/geometrylib/Line.cpp -o bin/o/Line.o
	g++ -c -Wall -std=c++17 src/geometrylib/Point.cpp -o bin/o/Point.o
	g++ -c -Wall -std=c++17 src/geometrylib/Shape.cpp -o bin/o/Shape.o
	g++ -c -Wall -std=c++17 src/geometrylib/Vector.cpp -o bin/o/Vector.o
	ar rcs src/lib/geometrylib.a bin/o/*.o
	ranlib src/lib/geometrylib.a
	cp src/geometrylib/main.hpp src/include/GEO
	cp src/geometrylib/*.inl src/include/GEO
	cp src/lib/*.so build/lib
	g++ -lX11 -pthread -Wl,-rpath,build/lib -Wall -std=c++17 src/game/*.cpp -L src/lib/geometrylib.a -I src/include -o bin/main bin/o/*.o src/main.cpp -L src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	
compilegeo:
	g++ -c -Wall -std=c++17 src/geometrylib/Calc.cpp -o bin/o/Calc.o
	g++ -c -Wall -std=c++17 src/geometrylib/ConvexShape.cpp -o bin/o/ConvexShape.o
	g++ -c -Wall -std=c++17 src/geometrylib/Line.cpp -o bin/o/Line.o
	g++ -c -Wall -std=c++17 src/geometrylib/Point.cpp -o bin/o/Point.o
	g++ -c -Wall -std=c++17 src/geometrylib/Shape.cpp -o bin/o/Shape.o
	g++ -c -Wall -std=c++17 src/geometrylib/Vector.cpp -o bin/o/Vector.o
	ar rcs src/lib/geometrylib.a bin/o/*.o
	ranlib src/lib/geometrylib.a
	cp src/geometrylib/main.hpp src/include/GEO
	cp src/geometrylib/*.inl src/include/GEO

compilegame:
	g++ -c -Wall -std=c++17 -I src/include src/game/Clickable.cpp -o bin/o/ClickableG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Collider.cpp -o bin/o/ColliderG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/ComplexLine.cpp -o bin/o/ComplexLineG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Curve.cpp -o bin/o/CurveG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Entity.cpp -o bin/o/EntityG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Game.cpp -o bin/o/GameG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Layer.cpp -o bin/o/LayerG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Player.cpp -o bin/o/PlayerG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Noise.cpp -o bin/o/NoiseG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Time.cpp -o bin/o/TimeG.o
	g++ -c -Wall -std=c++17 -I src/include src/game/Vector.cpp -o bin/o/VectorG.o
	ar rcs src/lib/game.a bin/o/*G.o
	ranlib src/lib/game.a

compile:
	g++ -lX11 -pthread -Wl,-rpath,bin -Wall -std=c++17 -L src/lib/game.a -L src/lib/geometrylib.a -I src/include -o bin/main bin/o/*.o src/main.cpp -L src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

compilemain:
	g++ -lX11 -pthread -Wl,-rpath,bin -Wall -std=c++17 -I src/include -o bin/main src/main.cpp -L src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

debug:
	g++ -g -Wl,-rpath,bin -Wall -std=c++17 -L src/lib/game.a -L src/lib/geometrylib.a -I src/include -o bin/main bin/o/*.o src/main.cpp -L src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	valgrind --leak-check=yes --track-origins=yes ./bin/main


test:
	g++ test.cpp src/lib/geometrylib.a -o test
	./test
	rm test

run:
	./bin/main
