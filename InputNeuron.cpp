#include "InputNeuron.h"
#include <string>
using std::string;

InputNeuron::InputNeuron(int thr=0,int sernum=0):MPNeurons(thr,sernum){
	
}

InputNeuron::~InputNeuron(){

}

void InputNeuron::stimulatetime(int stino){
	if(stino==0)	//input 0 to restrain this neuron
	  setSupFlag(true);
	else
	  addcountThrNum(stino);
}

const string InputNeuron::getType(){
	return "Input  Neuron";	//format problem when output
}

bool InputNeuron::OutputofIN(){
	if(IsActive())
	  return true;
	else
	  return false;
}
