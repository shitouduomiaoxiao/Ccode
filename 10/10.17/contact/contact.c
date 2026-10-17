#define  _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void mune() {
	printf("******************************************\n");
	printf("************1.add   2.del*****************\n");
	printf("************3.serch 4.motify**************\n");
	printf("************5.show  6.sort****************\n");
	printf("************0.exit************************\n");
	printf("******************************************\n");
}
//函数初始化
void initcon (con*p) {
	memset(p->data,0,sizeof(p->data));
	p->sz = 0;

}
//寻找人员
int SerByName (char*name, con*p) {
	int pos = 0;
	for (pos = 0; pos < peomax; pos++) {
		if (strcmp(name, p->data[pos].name) == 0)
		{
			return pos;
		}
	}
	printf("未找到该人员");

}
//增加人员
void add(con* p) {
	if (p->sz == peomax) {
		printf("通讯录已满\n ");
	}
	printf("请输入名字\n");
	scanf("%s",p->data->name);
	printf("请输入年龄\n");
	scanf("%d",&p->data->age);
	printf("请输入性别\n");
	scanf("%s",p->data->sex);
	printf("请输入地址\n");
	scanf("%s",p->data->post);
	printf("请输入电话\n");
	scanf("%s",p->data->tele);
	p->sz++;
}
//删减
void del(con* p) {
	//查找
	char name[20] = { 0 };
	printf("请输入你要找的名字");
	scanf("%s", &name[0]);
	int pos=SerByName(&name[0],p);
	for (int i = 0; i < peomax - pos - 1; i++) {
		p->data[pos + i] = p->data[pos + i + 1];
		p->sz--;
	}
	if (p->sz == 0) {
		printf("通讯录已空");

	}
}
//查找
void serch(const con* p) {
	char name[20] = { 0 };
	printf("请输入你要找的名字");
	scanf("%s", &name[0]);
	int pos = SerByName(&name[0], p);
	printf("%-20s\ts%-4d\t%-5s\t%-10s\t%-13s\t",
		p->data[pos].name,
		p->data[pos].age,
		p->data[pos].sex,
		p->data[pos].post,
		p->data[pos].tele);


}
//修改
void motify(con* p) {
	char name[20] = { 0 };
	printf("请输入你要找的名字");
	scanf("%s", &name[0]);
	int pos = SerByName(&name[0], p);
	printf("请输入名字\n");
	scanf("%s", p->data[pos].name);
	printf("请输入年龄\n");
	scanf("%d", &p->data[pos].age);
	printf("请输入性别\n");
	scanf("%s", p->data[pos].sex);
	printf("请输入地址\n");
	scanf("%s", p->data[pos].post);
	printf("请输入电话\n");
	scanf("%s", p->data[pos].tele);


}
//展示
void show(const con* p) {

	for (int i=0; i < p->sz; i++) {
		printf("%-20s\ts%-4d\t%-5s\t%-10s\t%-13s\t", 
			p->data[i].name,
			p->data[i].age,
			p->data[i].sex,
			p->data[i].post,
			p->data[i].tele);
	}
}
