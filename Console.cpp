//User Interface

#include "Console.h"
#include <deque>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

Console::Console(){
	NumofNeurs=0;
	changeflag=false;
	history.clear();
}

Console::~Console(){
	//delete[] NeuronsList;
	for(int i=NumofNeurs-1;i>=0;i--)
		delete NeuronsList[i];
	history.clear();
}

void Console::run(){
	displayMainMenu();
	int choice=0;
	cin>>choice;
		//EXCEPTION HANDLE
	while(choice!=0){
		if(choice==1){
			displayEditMenu();
			int echoice=0;
			cin>>echoice;
			while(echoice!=0){
				switch(echoice){
					case 1:
						create();
						break;
					case 2:
						destory();
						break;
					case 3:	
						status();
						break;
					case 4:
						connect();
						break;
					case 5:
						disconnect();
						break;
					case 6:
						undo();
						break;
					case 7:
						redo();
						break;
					case 8:
						readlog();
						break;
					case 9:
						savelog();
						break;
					default:
						break;
				}
				displayEditMenu();
				cin>>echoice;
				if(echoice==0&&changeflag){
					cout<<"Logfile is changed, do you want to save?(y/n): ";
					char yn2;
					cin>>yn2;
					if(yn2=='y')
					  savelog();
				}
			}
		}
		if(choice==2){
			displayRunMenu();
			int rchoice=0;
			cin>>rchoice;
			while(rchoice!=0){
				switch(rchoice){
					case 1:
						status();
						break;
					case 2:
						stimulate();
						break;
					default:
						break;
				}
				displayRunMenu();
				cin>>rchoice;
				if(rchoice==0&&changeflag){
					cout<<"Logfile is changed, do you want to save?(y/n): ";
					char yn3;
					cin>>yn3;
					if(yn3=='y')
					  savelog();
				}
			}
		}
		displayMainMenu();
		cin>>choice;
		//EXCEPTION HANDLE
	}
}

void Console::displayMainMenu(){
	cout<<"1.Edit Network\n2.Run Network\n0.Quit\n";
	cout<<"Please choose (0~2):";
}

void Console::displayEditMenu(){
	cout<<"1.Create a Neuron\n2.Delete a Neuron\n3.Show Status\n4.Make a Connection\n"
		<<"5.Disconnect\n6.Undo\n7.Redo\n8.Read Log\n9.Save Log\n0.Quit\n";
	cout<<"Please choose (0~9):";
}

void Console::displayRunMenu(){
	cout<<"1.Show Status\n2.Stimulate\n0.Quit\n";
	cout<<"Please choose (0~2):";
}

void Console::create(){
	cout<<"1.Input Neuron\n2.Middle Neuron\n3.Output Neuron\n0.Quit\n"
		<<"Please choose (0~3):";
	int typenum=0;
	cin>>typenum;
		//EXCEPTION HANDLE
	int Thrnum=0;
	switch(typenum){
		case 1:
			cout<<"Please set Threshold: ";
			Thrnum=0;
			cin>>Thrnum;
			NeuronsList[NumofNeurs]=new InputNeuron(Thrnum,NumofNeurs+1);
			NumofNeurs++;
			changeflag=true;
			break;
		case 2:
			cout<<"Please set Threshold: ";
			Thrnum=0;
			cin>>Thrnum;
			NeuronsList[NumofNeurs]=new MiddleNeuron(Thrnum,NumofNeurs+1);
			NumofNeurs++;
			changeflag=true;
			break;
		case 3:
			cout<<"Please set Threshold: ";
			Thrnum=0;
			cin>>Thrnum;
			NeuronsList[NumofNeurs]=new OutputNeuron(Thrnum,NumofNeurs+1);
			NumofNeurs++;
			changeflag=true;
			break;
		case 0:
		default:
			break;
	}
}

void Console::destory(){
	if(checkempty())
		return;
	cout<<"Which one do you want to delete?\n";
	status();
	cout<<"Please choose (1~"<<NumofNeurs<<",0 to Quit):";
	int delno=0;
	cin>>delno;
		//EXCEPTION HANDLE
	if(delno==0)
	  return;
	else if(delno<0||delno>NumofNeurs){
      cout<<"Error Flag 0.\n";
	  return;
	}
	else{
		if(NumofNeurs==1){
			delete NeuronsList[0];
			NumofNeurs=0;
		}
		else if(delno==NumofNeurs){
			delete NeuronsList[NumofNeurs-1];
			NumofNeurs--;
		}
		else{
			delete NeuronsList[delno-1];
			for(int i=delno-1;i<NumofNeurs-1;i++)
				NeuronsList[i]=NeuronsList[i+1];
			NeuronsList[NumofNeurs-2]=NeuronsList[NumofNeurs-1];
			//delete NeuronsList[NumofNeurs-1];   !!!
			NeuronsList[NumofNeurs-1]=NULL;
			NumofNeurs--;
		}
		changeflag=true;
	}
}

void Console::status(){
	cout<<"No."<<setw(7)<<"Type"<<setw(19)<<"Threshold"<<setw(15)<<"Status\t"<<setw(19)<<"Connection\n";
	for(int i=0;i<NumofNeurs;i++){
		cout<<i+1<<"."<<setw(7)<<NeuronsList[i]->getType()<<setw(19)<<NeuronsList[i]->getThreshold()
			<<setw(8)<<IsNActive(i)<<setw(19)<< NeuronsList[i]->getConSta()<<endl;
	}
}

void Console::connect(){
	if(checkempty())
		return;
	cout<<"Which two neurons do you want to connect?\n";
	status();
	cout<<"Please choose the 1st (1~"<<NumofNeurs<<",0 to Quit):";
	int con1st=0;
	cin>>con1st;
		//EXCEPTION HANDLE
	if(con1st<=0||con1st>NumofNeurs){
		cout<<"Error Flag 1.\n";	//EH
		return;
	}
	if(NeuronsList[con1st-1]->getType()=="Output Neuron"){
		cout<<"Error Flag 7. You cannot input into an Output Neuron.\n";
		return;
	}
	cout<<"Please choose the 2nd (1~"<<NumofNeurs<<",0 to Quit):";
	int con2nd=0;
	cin>>con2nd;
		//EXCEPTION HANDLE
	if(con2nd<=0||con2nd>NumofNeurs||con2nd==con1st){
		cout<<"Error Flag 2.\n";	//EH
		return;
	}
	if(NeuronsList[con2nd-1]->getType()=="Input Neuron"){
		cout<<"Error Flag 8. You cannot output to a Input Neuron.\n";
		return;
	}
	cout<<"Please choose connection type, 0 for SupConnect, 1 for InSupConnect: ";
	int conType=0;
	cin>>conType;
	if(conType!=0&&conType!=1){
		cout<<"Error Flag 9.\n";
		return;
	}
	ostringstream os0;
	os0<<con1st<<" "<<con2nd<<" "<<conType;
	string temp0=os0.str();
	NeuronsList[con1st-1]->setConSta(temp0);
	history.push_back("C "+temp0+"\n");
	changeflag=true;
}

void Console::disconnect(){
	if(checkempty())
		return;
	cout<<"Which neuron do you want to disconnect?\n";
	status();
	cout<<"Please choose (1~"<<NumofNeurs<<",0 to Quit):";
	int dcno=0;
	cin>>dcno;
	if(dcno<=0||dcno>NumofNeurs){
		cout<<"Error Flag 4.\n";	//EH
		return;
	}
	cout<<NeuronsList[dcno-1]->getConSta();
	cout<<"To which one(0 to Quit): ";
	int dcno1=0;
	cin>>dcno1;
	if(dcno1<=0||dcno1>NumofNeurs){
		cout<<"Error Flag 9.\n";	//EH
		return;
	}
	// if(dcno1)	//judge if they has connect
	ostringstream os1;
	os1<<dcno<<" "<<dcno1;
	string temp1=os1.str();
	history.push_back("D "+temp1+"\n");
	changeflag=true;
	//UNFINISHED
}

void Console::undo(){
	if(!history.empty()){
		histemp=history.back();
		history.pop_back();
		cout<<"Undo "<<histemp;
		changeflag=true;
	}
	else
	  cout<<"Error Flag 6. No history.\n";
}

void Console::redo(){
	if(histemp!=""){
		history.push_back(histemp);
		cout<<"Redo "<<histemp;
		histemp="";
		changeflag=true;
	}
	else
		cout<<"temp is empty. Error Flag 5.\n";
}

void Console::readlog(){
	if(changeflag){
		cout<<"Logfile is changed, do you want to save?(y/n): ";
		char yn2;
		cin>>yn2;
		if(yn2=='y')
			savelog();
	}
	cout<<"Please input readlogfile name: ";//Quit
	string logname;
	cin>>logname;
	ifstream in(logname.c_str());
	//check file
	string line;
	while(getline(in,line))
		history.push_back(line+"\n");
	in.close();
	//refresh connect status of neurons
}

void Console::savelog(){
	cout<<"Please input savelogfile name: ";//Quit
	string savename;
	cin>>savename;
	ofstream out(savename.c_str());
	//check file
	while(!history.empty()){
		/*string otemp;
		otemp=history.back();
		out<<otemp;	//
		history.pop_back();*/
		out<<history.front();
		history.pop_front();
	}
	//log the status of neuronslist, if head #(means it is a create or destory operation), donnot write in logfile
	out.close();
	changeflag=false;
}

void Console::stimulate(){
	if(checkempty())
		return;
	status();
	cout<<"Please choose a input neuron (0 to Quit):";
	int choice=0;
	cin>>choice;
	if(choice<=0||choice>NumofNeurs){
		cout<<"Error Flag 3.\n";	//EH
		return;
	}
	else{
		if(NeuronsList[choice-1]->getType()=="Input Neuron"){
			cout<<"Please input time(s) you want to stimulate :";
			int time=0;
			cin>>time;
			reinterpret_cast<InputNeuron*>(NeuronsList[choice-1])->stimulatetime(time);
		}
		else
			cout<<"It is not an input neuron.\n";	//EH
	}
}

bool Console::checkempty(){
	if(NumofNeurs==0){
		cout<<"No NumofNeurs,do you want to create now?(y/n):";
		char yn;
		cin>>yn;
		if(yn=='y'){
			create();
		}
		return true;
	}
	else
		return false;
}

string Console::IsNActive(int acno){
	if(NeuronsList[acno]->IsActive())
	  return "Active";
	else
	  return "Sup";
}
