//This Header is included the definition of the Neurons

#ifndef MPNEURONS_H
#define MPNEURONS_H

#include <string>
using std::string;

class MPNeurons{
	friend class InputNeuron;
	friend class MiddleNeuron;
	friend class OutputNeuron;
public:
	MPNeurons(int thr,int sernum);//(InThrNum,no)
	virtual ~MPNeurons();

	int getThreshold();
	int getcount();
	bool IsSup();
	bool IsActive();
	virtual const string getType()=0;
	const string getConSta();

	void setConSta(string);	//maybe not a good idea
private:
	int ThrNum;        //Threshold
	int countThrNum;   //how many time it has been sting
	//char* name;
	int no;			   //serial number in NeuronsList[]
	bool SupFlag;		   //restrain or not
	string connectstatus;	//as it say
	
	virtual void setThreshold(int);
	//void setName(char*);
	virtual void setno(int);
	void setSupFlag(bool);
	void addcountThrNum(int);
};

#endif
