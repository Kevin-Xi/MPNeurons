#ifndef MIDDLENEURON_H
#define MIDDLENEURON_H

#include "MPNeurons.h"

class MiddleNeuron:public MPNeurons{
public:
	MiddleNeuron(int,int);
	~MiddleNeuron();

	void supconnect(bool);	//if previous one output true, this one's countThrNum will +1
	void insupconnect(bool);	//if previous one output true, this one will be restrained
	const string getType();

private:
	bool OutputofMN();
};

#endif
