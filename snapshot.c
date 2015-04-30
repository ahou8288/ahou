#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snapshot.h"

#define NUM_FUNCTIONS 1

//Function Definitions
void getCommand(void);
void run(char* commandName, char* userCommand);
void BYE(char* args);

entry* entry_head = NULL;
entry* entry_tail = NULL;

snapshot* snapshot_head = NULL;
snapshot* snapshot_tail = NULL;

int main(void) {
	getCommand();
	return 0;
}

void getCommand(void){
	//Get user input
	char userCommand[MAX_LINE_LENGTH];
	fgets(userCommand,MAX_LINE_LENGTH,stdin);
	
	//Duplicate string because original string is modified.
	char args[MAX_LINE_LENGTH];
	strcpy(args,userCommand);
	
	char * pch;
	pch = strtok (userCommand," "); //Split string
	if (pch != NULL)
	{
		//At this point send user command to get processed at run(pch,usercommand)
		run(pch,args);
	}
	
}

void run(char* commandName, char* arguments){
	//Create a list of function names and function pointers
	//Run the function with the arguments
	
	struct functionList{
		char* name;
		void (*ptr)();
		int args;
	};
	
	struct functionList myFnc[NUM_FUNCTIONS];
	
	myFnc[0].name="BYE";
	myFnc[0].ptr=&BYE;
	myFnc[0].args=0;
	
	printf("%s\n",commandName);
	for (int i=0; i<NUM_FUNCTIONS; i++){
		if (strcmp(commandName,myFnc[i].name)==0){
			if (myFnc[i].args>0){
				(myFnc[0].ptr)(arguments);//FIX
			} else {
				(myFnc[0].ptr)();
			}
		}
	}
}

void BYE(){
	printf("Bye function has been run\n");
}
