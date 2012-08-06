#ifndef MIDDLENEURON_H
#define MIDDLENEURON_H

#include "MPNeurons.h"

class MiddleNeuron:public MPNeurons{
public:
	MiddleNeuron(int,int);
	~MiddleNeuron();

	void supconnect(bool);
	void insupconnect(bool);
	const string getType();

private:
	bool OutputofMN();
};

#endif
