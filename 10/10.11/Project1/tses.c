#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct stu {
	char name[20];
	int age;
};
int cmp_by_int(const void* e1,const void * e2) {

	return (*(int*)e1 - *(int*)e2);
}
void swap(char* x, char* y,int width)
{  
	int i = 0;
		for (i = 0; i < width; i++)
		{
			char mid = 0;
			mid = *(x + i);
			*(x + i) = *(y + i);
			*(y + i) = mid;

		}
}



void dul_cmp(void* bais, int sz, int width, int (*cmp)( void*, void*))
{
	int i = 0;
	for (i = 0; i < sz; i++)

	{
		int j = 0;

		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)bais + j * width, (char*)bais + (j + 1) * width)>0)
			{
				swap((char*)bais + j * width, (char*)bais + (j + 1) * width, width);
					
					
			}
		}

	}
}
void test1() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);

	dul_cmp(arr, sz, width, cmp_by_int);
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
cmp_by_age(const void* e1,const void* e2) {
	return(((struct stu*)e1)->age -( (struct stu*)e2)->age);
}
void test2() {
	struct stu s[] = { {"zhangshan",20},{"lisi",16},{"wangwu",18} };
	int sz = sizeof(s) / sizeof(s[0]);
	int width = sizeof(s[0]);
	dul_cmp(s, sz, width, cmp_by_age);
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", (s+i)->age);
	}
	printf("\n");
	
}


int main()
{
	//test1();
	test2();
	return 0;




}
	

	

