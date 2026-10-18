#pragma once

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define peomax 100 
#define namemax 20
#define sexmax 5
#define postmax 100
#define telemax 13
//草单
void mune();

 typedef  struct peo {
	char name[namemax];
	int age;
	char sex[sexmax];
	char post[postmax];
	char tele[telemax];
}peo;
 typedef struct contact {
	 peo data[peomax];
	 int sz;
 }con;
 //函数初始化
 void initcon(con*);
 //查询人员
 int SerByName(const char*, const con*);

 
 //增加人员
 void add(con*);
 //删除
 void del(con*);
 //查询并展示
 void serch(const con*);
 //修改
 void motify(con*);
 //展示
 void show(const con*);
 //比较
 int cmpbyname(void* , void* );
 //排序
 void sort(con*);

