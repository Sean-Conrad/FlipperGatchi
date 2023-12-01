all : build

build: 
	g++ -g -std=c++11 -Wall -c src/main.cpp -o main.exe 
	g++ -g -std=c++11 -Wall -c src/game/Player.cpp -o Player.o
	g++ -g -std=c++11 -Wall -c src/tasks/Task.cpp -o Task.o

run: ./main.exe

build_game_tests:
	rm -f game_tests.exe
	g++ -g -std=c++11 -Wall tests/game_tests.cpp -o game_tests.exe 

run_game_tests:
	./game_tests.exe 

build_shop_tests:
	rm -f shop_tests.exe
	g++ -g -std=c++11 -Wall tests/shop_tests.cpp -o shop_tests.exe

run_shop_tests:
	./shop_tests.exe 

build_tasks_tests:
	rm -f tasks_tests.exe
	g++ -g -std=c++11 -Wall tests/tasks_tests.cpp src/game/Player.cpp src/tasks/Task.cpp -o tasks_tests.exe 

run_tasks_tests: 
	./tasks_tests.exe 

build_player_tests:
	rm -f tasks_tests.exe
	g++ -g -std=c++11 -Wall tests/player_tests.cpp src/game/Player.cpp src/tasks/Task.cpp -o player_tests.exe 

run_player_tests: 
	./player_tests.exe 

other:
	g++ -o game src/main.cpp src/game/Player.cpp src/tasks/Task.cpp src/utils/Timer.cpp

clean:
	rm -f game