#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snapshot.h"

void getCommand(void);

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
	
	while (pch != NULL)
	{
		printf ("%s\n",pch);
		pch = strtok (NULL, " ");
	}
	char command[MAX_LINE_LENGTH];
	
	//Split string
	//send first line to function control
	//send arguments also
	
}
