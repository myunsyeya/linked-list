#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

#define KI _getch()
typedef struct node{
	char Data[32];
	struct node* p_next;
}NODE;

void addString(NODE** p);
void printString(NODE* p);
void freeString(NODE** p_head, NODE** p);

void deletionString();

int main() {
	NODE* p_head = (NODE*)malloc(sizeof(NODE));
	NODE* p = p_head;                                                             // 선언부 
	
	while(1){
		printf("1. 작성   2. 출력   3. 삭제   ESC. 끝\n\n");
		switch (KI) {
		case '1': system("cls"); while(KI != 27) addString(&p); break;
		
		printString(p_head);                                                      // 함수부 
		}
		system("cls"); 
	}
	freeString(&p_head, &p);
	system("pause");
	return 0;                                                                     // 후처리부 
}

void addString(NODE** p){
	if (*p != NULL){
		(*p)->p_next = (NODE*)malloc(sizeof(NODE));
		printf("문자열을 입력해주세요.\n\n*나가시려면 esc를 눌러주세요\n\n==> "); 
		scanf("%s", (*p)->Data);
		*p = (*p)->p_next;
		(*p)->p_next = NULL;
	}
	else{
		*p = (NODE*)malloc(sizeof(NODE));
		(*p)->p_next = (NODE*)malloc(sizeof(NODE));
		printf("문자열을 입력해주세요.\n\n*나가시려면 esc를 눌러주세요\n\n==> "); 
		scanf("%s", (*p)->Data);
		*p = (*p)->p_next;
		(*p)->p_next = NULL;
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
