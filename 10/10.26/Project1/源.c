#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int main() {
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int arr2[10] = { 0 };
//	memcpy(arr2, arr1, 20);
//	for (int i = 0; i < 10; i++) {
//		printf("%d", arr2[i]);
//		return 0;
//	}
//}
void *my_memmove(void* dst, void* src, int count) {
	void* ret = dst;
	
	if (dst <= src) {
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;

		}
	}
	else if (dst > src) {
		while (count--) {
			*((char*)dst + count) = *((char*)src + count);
			
		}
		return ret;
	}
	
}
int main() {
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int arr2[10] = { 0 };
	my_memmove(&arr1[2], &arr1[0], 20);
	for (int i = 0; i < 10; i++) {
		printf("%d", arr1[i]);
	}
	return 0;
	
}