#include "MPNeurons.h"
#include <iostream>
using namespace std;

MPNeurons::MPNeurons(int thr=0,int sernum=0){
	setThreshold(thr);
	setno(sernum);
	SupFlag=false;
	countThrNum=0;
}

MPNeurons::~MPNeurons(){

}

bool MPNeurons::IsSup(){
	return SupFlag;
}

void MPNeurons::setSupFlag(bool flag){
	SupFlag=flag;
}

void MPNeurons::addcountThrNum(int addno){
	if(addno<0){
		cout<<"Please input a plus.\n";
		return;
	}
	countThrNum+=addno;
}

bool MPNeurons::IsActive(){
	if((getcount()>=getThreshold())&&(!IsSup()))	//ThrNum=0 means this neuron is always output true as soon as it is not been restrained
		return true;
	else 
		return false;
}

int MPNeurons::getThreshold(){
	return ThrNum;
}

int MPNeurons::getcount(){
	return countThrNum;
}

void MPNeurons::setThreshold(int thre){
	ThrNum=thre;
}

void MPNeurons::setno(int sno){
	no=sno;
}

void MPNeurons::setConSta(string consta){
	if(connectstatus=="")
		connectstatus=consta;
	else
		connectstatus+="\t"+consta;	//convenient when it cout directly...
}

const string MPNeurons::getConSta(){
	return connectstatus;	//...although there is not so much things a Console(without GUI) can do. Using GUI is suitable and easy for this kind of program, so I decide to give up the Console
}
