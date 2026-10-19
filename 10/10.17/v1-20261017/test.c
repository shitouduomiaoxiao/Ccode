#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contact.h"
int main() {
	int ch= 0;
	//创建
	con on;
	//初始化
	initcon(&on);
		do {
		
			mune();
			printf("请选择模式");
			scanf("$d", &ch);
			switch (ch) {
			case1:
				add(&on);
				break;
			case2:
				del(&on);
				break;
			case3:
				serch(&on);
				break;
			case4:
				motify(&on);
				break;
			case5:
				show(&on);
				break;
			
			
		
			default:
				printf("打印错误\n");
			}



		} while (ch);
		printf("退出\n");



	
	return 0;
}