CXXFLAGS=

all: demo.o longest_sentence.o
	g++ demo.o -o demo
	g++ longest_sentence.o -o longest_sentence

demo.o: demo.cpp linked_list.hpp
	g++ ${CXXFLAGS} -c demo.cpp

longest_sentence.o: longest_sentence.cpp longest_sentence.hpp linked_list.hpp
	g++ ${CXXFLAGS} -c longest_sentence.cpp

clean:
	rm *.o demo longest_sentence
	@echo "  >> Removed *.o files!\n"
