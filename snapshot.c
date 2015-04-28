#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snapshot.h"

void getCommand(void);
void run(char* commandName, char* userCommand);
void BYE(void);


entry* entry_head = NULL;
entry* entry_tail = NULL;

snapshot* snapshot_head = NULL;
snapshot* snapshot_tail = NULL;

int main(void) {
	getCommand();
	return 0;
}

void getCommand(void){
	char userCommand[MAX_LINE_LENGTH];
	fgets(userCommand,MAX_LINE_LENGTH,stdin);
	char * pch;
	pch = strtok (userCommand," ");
	
	if (pch != NULL)
	{
		//At this point send user command to get processed at run(pch,usercommand)
		run(pch,userCommand);
	}
	
}

void run(char* commandName, char* userCommand){
	void (*byePtr)()=BYE;
	(*byePtr)();
}

void BYE(){
	printf("Bye\n");
}
