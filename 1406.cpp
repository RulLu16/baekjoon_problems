#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	char text;
	_Node* next;
	_Node* before;
}node;

node* textFile;

void addNode(char text){
	node* newOne=(node*)malloc(sizeof(node));
	
	newOne->text=text;
	newOne->before=textFile->before;
	newOne->next=textFile;
	if(textFile->before!=NULL){
		textFile->before->next=newOne;
	}
	textFile->before=newOne;
}

void printNode(){
	node* temp=textFile;
	while(temp->before!=NULL){
		temp=temp->before;
	}
	while(temp->next!=NULL){
		printf("%c",temp->text);
		temp=temp->next;
	}
	printf("\n");
}

void commandL(){
	if(textFile->before!=NULL){
		textFile=textFile->before;
	}
}

void commandD(){
	if(textFile->next!=NULL){
		textFile=textFile->next;
	}
}

void commandB(){
	node* temp=textFile->before;
	
	if(temp!=NULL){
		textFile->before=temp->before;
		if(temp->before!=NULL)
			temp->before->next=textFile;
		free(temp);
	}
}

void commandP(char text){
	node* temp=textFile->before;
	node* newOne=(node*)malloc(sizeof(node));
	
	newOne->text=text;
	newOne->next=textFile;
	newOne->before=temp;
	
	if(temp!=NULL)
		temp->next=newOne;
	textFile->before=newOne;
}

int main(){
	textFile=(node*)malloc(sizeof(node));
	textFile->before=NULL;
	textFile->next=NULL;
	
	int m;
	
	while(1){
		char temp;
		scanf("%1c",&temp);
		
		if(temp=='\n') break;
		
		addNode(temp);
	}
	scanf("%d",&m);
	
	for(int i=0;i<m;i++){
		char command;
		getchar();
		scanf("%1c",&command);
		
		switch(command){
			case 'L':
				commandL();
				break;
			case 'D':
				commandD();
				break;
			case 'B':
				commandB();
				break;
			case 'P':
				char temp;
				getchar();
				scanf("%1c",&temp);
				commandP(temp);
				break;
		}
	}
	printNode();
}
