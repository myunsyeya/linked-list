#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node{
	char Data[32];
	struct node* p_next;
}NODE;

void addString(NODE** p);
void printString(NODE* p);
void freeString(NODE** p_head, NODE** p);

int main() {
	NODE* p_head = (NODE*)malloc(sizeof(NODE));
	NODE* p = p_head;
	addString(&p);
	if(!strcmp(p_head->Data, "escape")) p_head->p_next->p_next = NULL;
	printString(p_head);
	freeString(&p_head, &p);
	system("pause");
	return 0;
}

void addString(NODE** p){
	char str[] = "escape";
	while(1){
	if (*p != NULL){
		(*p)->p_next = (NODE*)malloc(sizeof(NODE));
		printf("문자열을 입력해주세요.\n\n*나가시려면 escape를 입력해주세요\n\n==> "); 
		scanf("%s", (*p)->Data);
		if(!strcmp((*p)->Data, str)) return;
		*p = (*p)->p_next;
		(*p)->p_next = NULL;
	}
	else{
		*p = (NODE*)malloc(sizeof(NODE));
		(*p)->p_next = (NODE*)malloc(sizeof(NODE));
		printf("문자열을 입력해주세요.\n 나가시려면 escape를 입력해주세요\n\n==> "); 
		scanf("%s", (*p)->Data);
		if(!strcmp((*p)->Data, str)) return;
		*p = (*p)->p_next;
		(*p)->p_next = NULL;
	}
	}
}

void printString(NODE* p){
	int i;
	for(i = 0; p->p_next->p_next != NULL; i++){
	printf("==============%d==============\n\n", i);
	printf("입력한 것 : %s\n\n", p->Data);
	printf("==============================\n\n");
	p = p->p_next;
	}
}

void freeString(NODE** p_head, NODE** p){
	while (*p_head != NULL){
	*p = *p_head;
	*p_head = (*p)->p_next;
	free(*p);
	}
}
