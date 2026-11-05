#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct revlist
{
	int val;
	struct revlist* next;
	struct revlist* prve;

}revlist;
revlist* initrevlist();
revlist* buynode(int);
revlist* findnode( revlist*,int x);
void pushpos(revlist*,int x,revlist* );
void poppos(revlist*, revlist*);
void revpushback(revlist*, int);
void revpopback(revlist*);
void revpushfront(revlist*, int);
void revpopfront(revlist*);
void revprintf(revlist*);
void destroylist(revlist**);

