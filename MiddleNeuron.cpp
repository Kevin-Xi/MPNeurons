#include "MiddleNeuron.h"
#include <string>
using std::string;

MiddleNeuron::MiddleNeuron(int thr=0,int sernum=0):MPNeurons(thr,sernum){
	
}

MiddleNeuron::~MiddleNeuron(){

}

void MiddleNeuron::supconnect(bool input){
	if(input)
	  addcountThrNum(1);	//if input false, do nothing
}

void MiddleNeuron::insupconnect(bool input){
	if(input)
	  setSupFlag(true);	//if input false, do nothing
}

const string MiddleNeuron::getType(){
	return "Middle Neuron";
}

bool MiddleNeuron::OutputofMN(){
	if(IsActive())
	  return true;
	else 
	  return false;
}
