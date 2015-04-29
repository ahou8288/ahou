#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snapshot.h"

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

void run(char* commandName, char* args){
	//Create a list of function names and function pointers
	//Run the function with the arguments

	char* functionName="BYE";
	void (*byePtr)(char*)=BYE;
	printf("%s\n",commandName);
	if (strcmp(commandName,functionName)==0){
		(*byePtr)(args);
	}
}

void BYE(char* args){
	printf("Bye function arguments :%s\n",args);
	printf("Bye function has been run\n");
}
