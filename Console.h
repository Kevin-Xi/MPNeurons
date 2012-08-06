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
	void undo();
	void redo();
	void readlog();
	void savelog();
	void stimulate();

	bool checkempty();	//check if the NeuronsList is empty
	string IsNActive(int);	//get the status of a neuron

	MPNeurons* NeuronsList[MAXSIZE];
	int NumofNeurs;
	deque<string> history;
	string histemp;	//redo list
	bool changeflag;	//check if logfile change
};

#endif
