#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>
#define KI (char)_getch()

typedef struct node{
	char Data[32];
	struct node* p_next;
}NODE;

void init();
void add(NODE** p_head, NODE** p);
void addString(NODE** p_head, NODE** p, char* Data);
void printString(NODE* p);
void emtpyString(NODE* p_head);
void freeString(NODE** p_head, NODE** p);

int main() {
	NODE *p_head = NULL, *p = NULL;
	
	while(1){
	init();
	switch(KI){
		case '1': add(&p_head, &p); break;
		case '2': printString(p_head); break;
		case '3': emtpyString(p_head); break;
		case 27: freeString(&p_head, &p); return 0; break;
		default: break;
	}
	system("cls");
	}
	return 0;
}

void init(){
	printf("1. �Է�\n");
	printf("2. ���\n");
	printf("3. ����\n");
	printf("ESC. ����\n");
}

void add(NODE** p_head, NODE** p){
	system("cls");
	char Data[32];
	while(1){
		printf("���ڿ��� �Է����ֽʽÿ�.\n\n *�����÷���escape�� �Է����ֽʽÿ�.\n\n==> ");
		scanf("%s", Data);
		if(!strcmp(Data, "escape")) return;
		addString(p_head, p, Data);
	}
}

void addString(NODE** p_head, NODE** p, char* Data){
	if(*p_head != NULL){
			(*p)->p_next = (NODE*)malloc(sizeof(NODE));
			*p = (*p)->p_next;
			(*p)->p_next = NULL;
			strcpy((*p)->Data, Data);
	}
	else{
		*p_head = (NODE*)malloc(sizeof(NODE));
		*p = *p_head;
		(*p)->p_next = NULL;
		strcpy((*p)->Data, Data);
	}
}

void printString(NODE* p_head){
	system("cls");
	int i;
	NODE* p = p_head;
	for(i = 0; p != NULL; i++){
	printf("==============���============\n\n");
	printf("==============%d==============\n\n", i);
	printf("�Է��� �� : %s\n\n", p->Data);
	printf("==============================\n\n");
	p = p->p_next;
	}
	if(i == 0) printf("�ۼ��� ��尡 �����ϴ�.\n\n");
	system("pause");
}

void emtpyString(NODE* p_head){  
	system("cls");
	int i = 0;
	int number;
	NODE *p = p_head, *empty;
	while(p != NULL) {
		p = p->p_next;
		i++;	
	}
	printf("������� �ϴ� ����� ��ȣ�� �˷��ֽʽÿ�.\n\n*���� ����� ������ %d���Դϴ�.\n\n==> ", i);
	scanf("%d", &number);
	if(number == 9999) return;
	if(number < 0 || number >= i) { printf("�߸��� �Է��Դϴ�.\n\n"); system("pause"); return; }
	p = p_head;
	for(i = 0; i < number - 1; i++) p = p->p_next;
	empty = p->p_next;
	p->p_next = p->p_next->p_next;
	printf("������ ����� ������ %s�Դϴ�.\n\n", empty->Data);
	system("pause");
	free(empty);
}

void freeString(NODE** p_head, NODE** p){
	while (*p_head != NULL){
	*p = *p_head;
	*p_head = (*p)->p_next;	
	free(*p);
	}
}
