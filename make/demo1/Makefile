message: main.o SampleClass.o
	g++ main.o SampleClass.o -o message
	@echo "  >> main.cpp and/or SampleClass.cpp changed! Recompiled!\n"

main.o: main.cpp
	g++ -c main.cpp
	@echo "  >> main.cpp changed! Recompiled!\n"

SampleClass.o: SampleClass.cpp SampleClass.h
	g++ -c SampleClass.cpp
	@echo "  >> SampleClass.cpp and/or SampleClass.h changed! Recompiled!\n"

clean:
	rm *.o message
	@echo "  >> Removed *.o files!\n"
