CPP = g++
OFLAG = -o
.SUFFIXES : .o .cpp
.cpp.o :
	$(CPP) -c $<
main : main.o Console.o Console.o MPNeurons.o InputNeuron.o MiddleNeuron.o OutputNeuron.o
	$(CPP) $(OFLAG) main main.o Console.o MPNeurons.o InputNeuron.o MiddleNeuron.o OutputNeuron.o
Console.o : Console.cpp Console.h MPNeurons.h InputNeuron.h \
	MiddleNeuron.h OutputNeuron.h
MPNeurons.o : MPNeurons.h MPNeurons.cpp
InputNeuron.o : InputNeuron.h InputNeuron.cpp
MiddleNeuron.o : MiddleNeuron.h MiddleNeuron.cpp
OutputNeuron.o : OutputNeuron.h OutputNeuron.cpp
main.o :main.cpp

run :
	./main

clean :
	rm -rf *.o main *.*~ *~
