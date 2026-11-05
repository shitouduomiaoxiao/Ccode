#define  _CRT_SECURE_NO_WARNINGS
#include"linklist.h"
/* 【已修复】原来写成 int testrevlist() 却没有 return；
   main 里还写了 revlist* head = testrevlist(); 把 int 赋给指针（C4047）。
   现在返回 int 并补了 return 0。 */
int testrevlist(void) {
	revlist* phead =initrevlist();
	revpushfront(phead,2);
	revprintf(phead);
	revpushback(phead, 3);
	revprintf(phead);
	revlist* pos = findnode(phead, 2);
	pushpos(phead, 1, pos);
	revprintf(phead);
	destroylist(&phead);

	return 0;
}
int main() {
	testrevlist();
	return 0;
}