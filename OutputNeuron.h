#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

#include "MPNeurons.h"

class OutputNeuron:public MPNeurons{
public:
	OutputNeuron(int,int);
	~OutputNeuron();

	void supconnect(bool);
	void insupconnect(bool);	//nothing different with previous kinds of neurons
	const string getType();

private:
	bool OutputofON();
};

#endif
