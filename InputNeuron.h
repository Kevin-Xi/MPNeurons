#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include "MPNeurons.h"

class InputNeuron:public MPNeurons{
public:
	InputNeuron(int,int);
	virtual ~InputNeuron();

	void stimulatetime(int);	//the number of stimulate
	const string getType();

private:
	bool OutputofIN();
};

#endif
