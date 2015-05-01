#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "snapshot.h"

#define NUM_FUNCTIONS 5

//Function Definitions
void getCommand(void);
void run(char* commandName, char* userCommand);
void BYE(char* args);
void SET(char* args);
void GET(char* args);
void append(char* args);
void help(void);
char* strLower(char* inString);

//Snapshot 1
struct snapshot snapPtr;

entry* entry_head = NULL;
entry* entry_tail = NULL;

snapshot* snapshot_head = NULL;
snapshot* snapshot_tail = NULL;

int main(void) {
	while (1){getCommand();}
	return 0;
}

void getCommand(void){
	//Get user input
	char userCommand[MAX_LINE_LENGTH];
	fgets(userCommand,MAX_LINE_LENGTH,stdin);
	
	//Remove trailing newline
	strtok(userCommand,"\n");

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
	
	myFnc[0].name="bye";
	myFnc[0].ptr=&BYE;
	myFnc[0].args=0;
	myFnc[1].name="set";
        myFnc[1].ptr=&SET;
        myFnc[1].args=1;
        myFnc[2].name="get";
        myFnc[2].ptr=&GET;
        myFnc[2].args=1;
        myFnc[3].name="append";
        myFnc[3].ptr=&append;
        myFnc[3].args=1;
        myFnc[4].name="help";
        myFnc[4].ptr=&help;
        myFnc[4].args=0;

	// printf("Command name is %s\n",strLower(commandName));
	for (int i=0; i<NUM_FUNCTIONS; i++){
		printf("%s --- %s\n",commandName,myFnc[i].name);
		if (strcmp(strLower(commandName),myFnc[i].name)==0){
			if (myFnc[i].args>0){
				(myFnc[i].ptr)(arguments);
			} else {
				(myFnc[i].ptr)();
			}
			break;
		}
	}
}

char* strLower(char* inString){
	for (int i=0; inString[i];i++){
		inString[i] = tolower(inString[i]);
	}
	return inString;
}

void BYE(){
	printf("bye\n");
	exit(0);
}

void SET(char* args){
	char key[MAX_KEY_LENGTH];
	int value;
	char command[MAX_LINE_LENGTH]; //not used
	sscanf(args,"%s %s %d",command,key,&value);
	printf("set command has received key of %s, and value of %d.\n",key,value);
	
	//Assums only one set done for each snapshot.
	struct value valPtr;
	valPtr.next=0;
	valPtr.prev=0;
	valPtr.value=value;

	struct entry entryPtr;
	entryPtr.values=&valPtr;
	entryPtr.next=0;
	entryPtr.prev=0;
	memcpy(&key,&entryPtr.key,MAX_KEY_LENGTH);

	snapPtr.entries=&entryPtr;
	snapPtr.next=0;
	snapPtr.prev=0;
	snapPtr.id=1;

	printf("Value put is %d.\n",snapPtr.entries->values->value);
}

void GET(char* args){
	char key[MAX_LINE_LENGTH];
	char command[MAX_LINE_LENGTH];
	sscanf("%s %s",command,key);
	if (&snapPtr.entries->values!=0){ //Where key = key!
		printf("[");

		//Traverse the list and print each value
		struct value ptr;
		ptr.next=snapPtr.entries->values->next;
		ptr.prev=0;
		while (ptr.next!=0){
			printf("%d ",ptr.value);
	                ptr.prev=ptr.next;
        	        ptr.next=ptr.next->next;
		}
		printf("]\n");
		//printf("[%d]\n",snapPtr.entries->values->value);
	}else{
		printf("[]\n");
	}
}

void append(char* args){
	char key[MAX_KEY_LENGTH];
        int value;
        char command[MAX_LINE_LENGTH]; //not used
        printf("Args to append function are %s\n",args);
	sscanf(args,"%s %s %d",command,key,&value);

	printf("test 2\n");
	//Reach the end of the list
	struct value ptr;
	ptr.prev=0;
	ptr.next=snapPtr.entries->values->next;
	
	printf("test\n");

	//printf("%d\n",ptr.next);
	while (ptr.next!=0){
		printf("next address\n");
		ptr.prev=ptr.next;
		ptr.next=ptr.next->next;
	}
	
	//tme="append";
	//        myFnc[3].ptr=&append;
	//                myFnc[3].args=1;
	//                mpVal->next=&newVal;
	//newVal.prev=tmpVal;
	//newVal.next=0;
}

void help(void){
	printf("%s",HELP);
}
