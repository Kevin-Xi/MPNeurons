//User Interface

#ifndef CONSOLE_H
#define CONSOLE_H

#define MAXSIZE 100

#include "MPNeurons.h"
#include "InputNeuron.h"
#include "MiddleNeuron.h"
#include "OutputNeuron.h"
#include <deque>
#include <string>

using std::deque;
using std::string;

class Console{
public:
	Console();
	virtual ~Console();

	void run();
private:
	void displayMainMenu();
	void displayEditMenu();
	void displayRunMenu();
	void create();
	void destory();
	void status();
	void connect();
	void disconnect();
	void undo();	//take advantage of deque
	void redo();	//pop the last undo to temp
	void readlog();	//from head of logfile
	void savelog();	//from head of history, so the logfile can keep correct order
	void stimulate();	//use in RunMenu, check if it is an input neuron and stimulate it

	bool checkempty();	//check if the NeuronsList is empty and ask to create
	string IsNActive(int);	//get the status of a neuron(int is the number in NeuronsList, use in status())

	MPNeurons* NeuronsList[MAXSIZE];	//store neurons, deserve to consider using STL
	int NumofNeurs;	//in NeuronsList
	deque<string> history;	//store history, use in savelog(), undo()
	string histemp;	//redo list
	bool changeflag;	//check if logfile change, use when Quit  without save and in some functions
};

#endif
