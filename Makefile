all				:	Program3

Program3		:   Games.o Main.o	
					g++ -o Program3.exe Games.o Main.o
				
Main.o			:	Main.cpp
					g++ -I ./ -c Main.cpp

Games.o			:	Games.cpp
					g++ -I ./ -c Games.cpp

clean			:	Program3.exe
					del *.o
					del Program3.exe