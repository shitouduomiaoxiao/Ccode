#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

//二维数组的传址调用
//void concept(int (*p)[5]) {
//
//	for(int i=0;i<5;i++){
//	
//		for (int f = 0; f < 5; f++) {
//			p[i][f] = f;
//		}
//	
//	}
//
//
//}
//
//
//
//
//
//
//int main() {
//
//	int a[5][5] = { 0 };
//	int (*p)[5] = a;
//	concept (p);
//
//	for (int i = 0; i < 5; i++) {
//
//		for (int f = 0; f < 5; f++) {
//			printf(" %d", a[i][f]);
//		}
//		printf("\n" );
//	}
//
//	return 0;
//}
// strlen函数的实现
// 在递归方式时my_strlen2(++p)中的p如果是后置++是会先执行函数然后++导致每次递出时调用的都是my_strlen2(p)导致栈溢出崩溃
//
// 普通比对
//size_t my_strlen1( char*p) {
//	int count = 0;
//	while (*p ) {
//		count++;
//		p++;
//
//	}
//	return count;
//}
//递归方式
//int my_strlen2(char*p) {
//	if (*p == '\0') {
//		return 0;
//	}
//	else return 1 + my_strlen2(++p);
//}
//指针运算方式
//int my_strlen3(char* p) {
//	char* q = p;
//	while (*p) {
//		p++;
//		
//	}
//	return p - q;
//}
//int main() {
//	char* p = "abcdeggh";
//	char* g = "hello world";
//	//int ret=strlen(p);
//	//int ret = my_strlen1(p);
//	//int ret = my_strlen2(p);
//	//int ret = my_strlen3(p);
//
//
//
//	printf("%d", ret);
//
//	return 0;
//}
//

//strcpy函数的实现
// 出现错误：cpy会将\0也copy进去所以打印时并不会出现只改变部分输出应为hello
//char* my_strcpy(char* p, const char* q)
//{	
//	char* dest = p;
//	while (*p = *q) {
//		p++;
//		q++;
//	}
//	return dest;
//}
//int main() {
//	char a[20] = "abcdefmmm";
//	char* p = &a[0];
//	char* q = "hello";
//	char* ret = my_strcpy(p, q);
//	printf("%s", ret);
//	return 0;
//}
//
//stract函数的实现
// 出现过的错误;当p++放在while中最后一次出循环时p++依旧会执行所以指针会跳过\0所以应该放在循环体内
//char* my_strcat(char* p, const char* q) {
//	char* ret = p;
//		while (*p) {
//			p++;
//		}
//		while (*p++ = *q++) {
//			;
//		}
//		return ret;
//
//}
//int main()
//{
//	char a[20] = "abcdefg";
//	char* p = &a[0];
//	char* q = "hello";
//	char * ret = my_strcat(p, q);
//	printf("%s", ret);
//	return 0;
//
 //}
# include <assert.h>
char* my_strstr(char* p, const char* q) {
	assert(p != 0);
	assert(q != 0);
	char* cp = q;
	char* base = p;


	while (*p != *cp) {
		p++;
		if (*p == 0) {
			return NULL;
		}

	}
	while(*base){
		cp = q;
		while (*cp) {
			base = p;

			while (*p == *cp) {

				p++;
				cp++;
			}
			p = base + 1;

		}
		return base;


	}
}


int main() {
	char a[30] = "abcdefghijklmn";
		char* p = &a[0];
		char* q = "fgh";
		char* ret = my_strstr(p, q);
		printf("%s", ret);

}