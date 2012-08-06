//This Header is included the definition of the Neurons

#ifndef MPNEURONS_H
#define MPNEURONS_H

#include <string>
using std::string;

class MPNeurons{
	friend class InputNeuron;	//in order to use setSupFlag() and addcountThrNum() in its inher
	friend class MiddleNeuron;
	friend class OutputNeuron;
public:
	MPNeurons(int thr,int sernum);//(ThrNum,no)
	virtual ~MPNeurons();

	int getThreshold();
	int getcount();
	bool IsSup();	//return true when is Sup
	bool IsActive();	//return false when it is not active in this time, else return true. use in Console::status()
	virtual const string getType()=0;	//use in Console::status()
	const string getConSta();	//use in Console::status()

	void setConSta(string);	//maybe not a good idea
private:
	int ThrNum;        //Threshold
	int countThrNum;   //how many time it has been sting
	int no;			   //serial number in NeuronsList[],maybe useful in Console::history
	bool SupFlag;		   //restrain or not
	string connectstatus;	//as it say, and use in Console::status()
	
	void setThreshold(int);
	void setno(int);
	void setSupFlag(bool);
	void addcountThrNum(int);
};

#endif
