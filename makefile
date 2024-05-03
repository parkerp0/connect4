bld = build/
cFlags = 

$(bld)final: $(bld)main.o $(bld)printer.o $(bld)board.o $(bld)engine.o $(bld)
	g++ $(cFlags) $(bld)main.o $(bld)printer.o $(bld)board.o $(bld)engine.o -lncurses -o $(bld)final


$(bld)main.o: main.cpp
	g++ $(cFlags) -c main.cpp -o $(bld)main.o

$(bld)printer.o: printer.cpp printer.hpp
	g++ $(cFlags) -c printer.cpp -o $(bld)printer.o

$(bld)board.o: board.cpp board.hpp
	g++ $(cFlags) -c board.cpp -o $(bld)board.o

$(bld)engine.o: engine.cpp engine.hpp
	g++ $(cFlags) -c engine.cpp -o $(bld)engine.o


$(bld):
	mkdir build

debugVal: $(bld) clean $(bld)final
	valgrind --log-file="debug.txt" ./$(bld)final

debug: $(bld) clean $(bld)final
	gdb ./$(bld)final

clean:
	rm -f $(bld)*

package: clean
	git log > CHANGELOG.txt