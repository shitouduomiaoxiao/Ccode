#pragma once

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define peomax 100 
#define namemax 20
#define sexmax 5
#define postmax 100
#define telemax 13
#define defsz 3
#define inc_size 2
//菜单
void menu();

 typedef  struct peo {
	char name[namemax];
	int age;
	char sex[sexmax];
	char post[postmax];
	char tele[telemax];
}peo;
 //静态版本创建通寻录
 //typedef struct contact {
	// peo data[peomax];
	// int sz;
 //}con;
 //动态版创建声明
 typedef struct con {
	 peo* data;
	 int sz;
	 int cap;

 }con;
 //函数动态初始化
 void initcon(con*);
 //函数静态初始化
 //void initcon(con*);
 // 释放空间
 void freecon(con*);
 //查询人员
 int SerByName(const char*, const con*);

 //扩容
 void addn(con*);
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
 int cmpbyname(const void* , const void* );
 //排序
 void sort(con*);
 //读取文件 
  
 void fliein(con*);
 //存入文件
 void flieput(con* );

