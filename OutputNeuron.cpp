#include "OutputNeuron.h"
#include <string>
using std::string;

OutputNeuron::OutputNeuron(int thr=0,int sernum=0):MPNeurons(thr,sernum){
	
}

OutputNeuron::~OutputNeuron(){

}

void OutputNeuron::supconnect(bool input){
	if(input)
	  addcountThrNum(1);
}

void OutputNeuron::insupconnect(bool input){
	if(input)
	  setSupFlag(true);
}

const string OutputNeuron::getType(){
	return "Output Neuron";
}

bool OutputNeuron::OutputofON(){
	if(IsActive())
	  return true;
	else
	  return false;
}
