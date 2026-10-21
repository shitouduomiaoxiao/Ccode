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
			scanf("%d", &ch);
			switch (ch) {
			case 1:
				add(&on);
				break;
			case 2:
				del(&on);
				break;
			case 3:
				serch(&on);
				break;
			case 4:
				motify(&on);
				break;
			case 5:
				show(&on);
				break;
			case 6:
				sort(&on);
				break;
			case 0:
				printf("退出");
					break;
			
		
			default:
				printf("输入错误\n");
			}



		} while (ch);
		freecon(&on);
		



	
	return 0;
}