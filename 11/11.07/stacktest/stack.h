#pragma once
#define Datatype int 
#define CAPACITE 4
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef struct Stack {
	Datatype* a;
	int top;
	int capacity;
}ST;
void STInit(ST*);
void STDestroy(ST*);
void STopush(ST*,Datatype);
void STpop(ST*);
Datatype StackTop(ST*);
bool STEtmpy(ST*);
