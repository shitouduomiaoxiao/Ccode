#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#define  initcapacity 4
typedef int datatype;
typedef struct seqlist {
	datatype* list;
	int size;
	int capacity;

}slist;
//初始化
bool initseqlist(slist*);
//扩容
bool seqlistcheckcapacity(slist*);
//销毁
void seqlistdestroy(slist*);
//头插
bool slpushfront(slist*, datatype);
//头删
void slpopfront(slist*);
//尾插
bool slpushback(slist*,datatype);
//尾删
void slpopback(slist*);
//任意处插入
bool slpush(slist*,datatype,int);
//任意位置删除
void slpop(slist*, int);
//查找
int slsearch(slist*, int);
//打印
void slprintf(slist*);

