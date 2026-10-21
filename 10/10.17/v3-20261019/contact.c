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
//函数动态初始化
void initcon(con* p) {
	p->sz = 0;
	p -> data = NULL;
	p->cap = 0;
	peo* ptr = (peo*)calloc(defsz, sizeof(peo));
	if (ptr == NULL) {
		perror("calloc");
		return ;
	}
	p->data = ptr;
	ptr = NULL;
	p->cap = defsz;
	
}
////函数初始化
//void initcon (con*p) {
//	memset(p->data,0,sizeof(p->data));
//	p->sz = 0;
//
//}
//寻找人员
int SerByName (const char*name, const con*p) {
	int pos = 0;
	for (pos = 0; pos < p->sz; pos++) {
		if (strcmp(name, p->data[pos].name) == 0)
		{
			return pos;
		}
	}
	printf("未找到该人员");
	return -1;

}
//释放空间
void freecon(con* p) {
	free(p->data);
	p->data = 0;
	p->sz = 0;
	p->cap = 0;
}
//动态增加人员
void add(con* p) {
	if (p->sz == p->cap) {
		
		peo* ptr = (peo*)realloc(p->data, sizeof(peo) * (p->cap+inc_size));
		if (ptr == NULL) {
			perror("perror");
			return ;
		}
		else {
			p->data = ptr;
			ptr = NULL;
		}
			p->cap += inc_size;
	}
	

		printf("请输入名字\n");
		scanf("%s", p->data[p->sz].name);
		printf("请输入年龄\n");
		scanf("%d", &p->data[p->sz].age);
		printf("请输入性别\n");
		scanf("%s", p->data[p->sz].sex);
		printf("请输入地址\n");
		scanf("%s", p->data[p->sz].post);
		printf("请输入电话\n");
		scanf("%s", p->data[p->sz].tele);
		p->sz++;

	
}

////静态增加人员
//void add(con* p) {
//	if (p->sz == peomax) {
//		printf("通讯录已满\n ");
//		return;
//	}
//	printf("请输入名字\n");
//	scanf("%s",p->data[p->sz].name);
//	printf("请输入年龄\n");
//	scanf("%d",&p->data[p->sz].age);
//	printf("请输入性别\n");
//	scanf("%s",p->data[p->sz].sex);
//	printf("请输入地址\n");
//	scanf("%s",p->data[p->sz].post);
//	printf("请输入电话\n");
//	scanf("%s",p->data[p->sz].tele);
//	p->sz++;
//}
//删减
void del( con* p) {
	//查找
	char name[20] = { 0 };
	printf("请输入你要找的名字");
	scanf("%s", &name[0]);
	int pos=SerByName(&name[0],p);
	if (pos == -1) {
		printf("查找失败");
		return;
	}
	for (int i=pos; i < p->sz-1; i++) {
		p->data[i] = p->data[i+1];
		
	}
	p->sz--;
		printf("成功");
	if (p->sz == 0) {
		printf("通讯录已空");
		return;

	}
}
//查找
void serch(const con* p) {
	char name[20] = { 0 };
	printf("请输入你要找的名字");
	scanf("%s", &name[0]);
	int pos = SerByName(&name[0], p);
	
	printf("%-20s\t%-4d\t%-5s\t%-10s\t%-13s\n",
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
	if (pos == -1) {
		printf("查找失败");
		return;
	}
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
		printf("%-20s\t%-4d\t%-5s\t%-10s\t%-13s\n", 
			p->data[i].name,
			p->data[i].age,
			p->data[i].sex,
			p->data[i].post,
			p->data[i].tele);
	}
}
//比较函数
int cmpbyname(const void*e1,const void*e2) {
	return strcmp(((const peo*)e1)->name,(( const peo*)e2)->name);

}
//排序
void sort(con* p) {
	qsort(p->data, p->sz, sizeof(p->data[0]), cmpbyname);
}