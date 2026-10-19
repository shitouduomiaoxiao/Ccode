#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
//int main() {
//	
//	char* p = (char*)malloc(40);
//	if (p == NULL) {
//		perror("molloc");
//		return 1;
//	}
//	else {
//		for (int i = 0; i < 10; i++) {
//			p[i] = 'q';
//		}
//	}
//	printf(p);
//	free(p);
//	p = NULL;
//
//	
//	return 0;
//}
//int main() {
//
//	char* pc = NULL;
//	char* p = (char*)realloc(pc, 40);
//	if (p == NULL) {
//		perror("realloc");
//		return 1;
//	}
//	else {
//		pc = p;
//		p = NULL;
//		for (int i = 0; i < 10; i++) {
//			pc[i] = 'q';
//		}
//		printf(pc);
//	}
//	free(pc);
//	pc = NULL;
//	return 0;
//}
// calloc可以开辟空间并初始化
//int main() {
//	char* pc = NULL;
//	char* p = calloc(10, 1);
//	if (p == NULL) {
//		perror("calloc");
//		return 1;
//	}
//	else {
//		pc = p;
//		p = NULL;
//		for (int i = 0; i < 5; i++) {
//			pc[i] = 'q';
//
//		}
//		printf(pc);
//	}
//	free(pc);
//	pc = NULL;
//	return 0;
//
//}