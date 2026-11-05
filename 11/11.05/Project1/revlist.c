/* ============================================================
   本文件此前踩过的坑（按出现顺序）：
   1. initrevlist 返回局部变量地址 -> 哨兵不存在 -> 死循环
   2. pushpos / poppos 里的 while 缺 cur = cur->next -> 死循环
   3. revpushback 传错位置（应为 phead，不是 phead->prve）
   4. poppos 缺 pos == phead 判断 -> free 掉哨兵 -> 崩溃
   5. buynode 返回 NULL 未检查
   6. 文件第一行曾误写 #pragma once（头文件指令），已删除
   7. 工程里 revlist.c 曾被登记为“头文件”(ClInclude)，不参与编译
      -> 链接报 LNK2019 无法解析的外部符号
   ============================================================ */

#include "linklist.h"
/* 【已修复】原来写成：revlist head; head.next = &head; head.prve = &head; return &head;
   返回的是栈上局部变量的地址，函数一返回就失效。哨兵根本不存在于堆上，
   后续 while (cur != phead) 沿着野地址走，永远回不到 phead —— 表现为死循环。
   => 哨兵必须和普通节点一样 malloc 出来。 */
revlist* initrevlist (){
	revlist* phead =(revlist*) malloc(sizeof(revlist));
	if (phead == NULL) {
		perror("malloc");
		return NULL;
	}
	phead->val = -1;
	phead->next = phead;
	phead->prve = phead;
	return phead;
}
/* 【已修复】malloc 之后没有判空，失败时会对 NULL 解引用。现在失败即返回 NULL。 */
revlist* buynode(int x) {
	revlist* newnode=(revlist*)malloc(sizeof(revlist));
	if (newnode == NULL) {
		perror("malloc");
		return NULL;
	}

	newnode->val = x;
	newnode->next = NULL;
	newnode->prve = NULL;
	return newnode;
}
revlist* findnode(revlist* phead,int x) {
	revlist* cur = phead->next;
	while (cur != phead) {
		if (cur->val == x) {
			return cur;
		}
		cur = cur->next;
	}
	printf("未找到该节点\n");
	return NULL;
}
/* 【已修复】原来套了一层 while (cur != phead) 去“查找 pos”，而且循环里忘了 cur = cur->next，
   一旦 pos 不在链表里就是死循环。其实 pos 是调用方给的有效节点，直接用它的 prve 即可，
   根本不需要搜索。另外 buynode 可能返回 NULL，要先判断再解引用。 */
void pushpos(revlist*phead,int x,revlist* pos) {
	assert(pos);
	revlist* newnode = buynode(x);
	if (newnode == NULL) {
		printf("开辟失败");
		return;
	}
		newnode->prve = pos->prve;
		newnode->prve->next = newnode;
		newnode->next = pos;
		pos->prve = newnode;
}
/* 【已修复】原来只 assert(pos)，没有挡 pos == phead。空表时 revpopback/revpopfront
   传进来的正是哨兵本身，于是 free(phead) 把哨兵的环拆了，
   下一次打印就会访问已释放内存（表现为访问冲突 0xC0000005 或堆损坏 0xC0000374）。
   哨兵不存数据，删它等于毁掉整条链表的骨架，必须拦下。

   注意两种失败原因不同：
     pos == NULL   —— 调用方给的节点不存在（findnode 没找到）
     phead->next == phead —— 链表真的是空的 */
void poppos(revlist*phead,revlist* pos) {
	if (pos == NULL) {
		return;
	}
	if ( pos == phead) {
		printf("链表为空\n");
		return;
		   }
			revlist* prve = pos->prve;
			prve->next = pos->next;
			pos->next->prve = prve;
			free(pos);
}
/* 【改进】原来参数是 revlist*，释放后调用方的 phead 仍指向已释放内存。
   改成二级指针，销毁后置 NULL，避免留下悬垂指针。 */
void destroylist(revlist**pphead) {
	revlist* cur=(*pphead)->next;
	revlist* tail = NULL;
	while (cur != *pphead) {
		tail = cur->next;
		free(cur);
		cur = tail;
		
	}
	free(*pphead);
	*pphead = NULL;
}
/* 【已修复】原来传 phead->prve（最后一个节点），而 pushpos 的语义是“插到 pos 之前”，
   结果新节点插到了末尾节点的前面，不是真正的尾插。
   尾插 = 插到哨兵之前，应该传 phead。 */
void revpushback(revlist* phead,int x) {
	pushpos(phead, x, phead);
}
/* 空表时 phead->prve == phead，由 poppos 里的判断拦下，不会误删哨兵。 */
void revpopback(revlist* phead) {
	poppos(phead, phead->prve);
}
void revpushfront(revlist* phead, int x) {
	pushpos(phead, x, phead->next);
}
/* 空表时 phead->next == phead，同样由 poppos 拦下。 */
void revpopfront(revlist* phead) {
	poppos(phead,phead->next);
}
/* 【已修复】原来 cur = cur->next 缩进错位，看起来像在 if 里面，容易误读。 */
void revprintf(revlist* phead) {
	revlist* cur = phead->next;
	while (cur!= phead) {
		printf("%d  ", cur->val);
			cur = cur->next;
	}
	printf("\n");
}