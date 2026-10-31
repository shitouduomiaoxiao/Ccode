#define  _CRT_SECURE_NO_WARNINGS
#include"SinglyLinkList.h"


SllNode* creatsllnode(int x) {
	SllNode* ptr= (SllNode*)malloc(sizeof(SllNode));
	if (!ptr) {
		perror("malloc");
		return NULL;
	}

	ptr->val = x;
	ptr->next = NULL;
	return ptr;
}
void  SllPushNodeFront(SllNode**pphead,int x) {
	assert(pphead);
	
	if (*pphead == NULL) {
		*pphead = creatsllnode(x);
		return;
	}
	SllNode* newnode = creatsllnode(x);
	newnode->next = *pphead;
	*pphead = newnode;
	

}
void SllPopNodeFront(SllNode** pphead) {
	assert(pphead);
	if (!*pphead) {
		printf("链表已空无法删除\n");
		return;
	}
	SllNode* ptr = (*pphead)->next;
	free(*pphead);
	*pphead = ptr;

}
void SllPushNodeBack(SllNode** pphead, int x) {
	assert(pphead);
	SllNode* cur = *pphead;
	if (*pphead == NULL) {
		*pphead = creatsllnode(x);
		return;
	}
	while (cur->next != NULL) {

		cur = cur->next;
	}
	cur->next = creatsllnode(x);
}
/* 注意：链表只有一个结点时 cur->next 为 NULL，
   若直接写 cur->next->next 会崩溃，必须把单结点情况单独处理 */
void SllPopNodeBack(SllNode** pphead) {
	assert(pphead);
	if (!*pphead) {
		printf("链表已空删除失败\n");
		return;
	}
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
		return ;
	}
	SllNode* cur = *pphead;
	
	while (cur->next->next != NULL) {
		cur = cur->next;

	}
	free(cur->next);
	cur->next = NULL;
}
void Sllprintf(SllNode* phead) {
	if (!phead) {
		printf("NULL\n");
		return;
	}
	SllNode * cur = phead;
	while (cur != NULL) {
		
		/* 原来写成 printf("%d", ...)，2->3 会打印成 "23"，加分隔符后才正常 */
		printf("  %d", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
/* 曾经把 cur = cur->next 写在 if 前面：会跳过头结点，
   且 cur 变成 NULL 后仍访问 cur->val，导致崩溃。
   另：assert(phead) 会让空链表查找直接中止，
   若允许查空表可改为 if (phead == NULL) return NULL; */
SllNode* SllSearch(SllNode*phead,int x) {
	assert(phead);
	SllNode* cur = phead;
	while (cur!=NULL) {
		
		if (cur->val == x) {
			return cur;
		}
		cur = cur->next;
	}
	printf("没找到\n");
	return NULL;
}
/* 曾经的错误：while 里既不推进 cur，又每轮新建并插入结点，
   pos 不是头结点时会不断插入直到内存耗尽。
   现在先找前驱；若 pos 不在本链表中，cur 会走到 NULL，由下面的判断安全返回。 */
void SllPushNodePos(SllNode** pphead, SllNode* pos, int x){
	assert(pphead);
	assert(pos);
	assert(*pphead);
	SllNode* cur = *pphead;

	if (*pphead == pos) {
		
		SllPushNodeFront(pphead, x);
		return;
	}
	while (cur!=NULL&&cur->next!= pos) {
		cur = cur->next;
	}
	if (cur == NULL) {
		return;
	}
	SllNode* node = creatsllnode(x);
		node->next = pos;
		cur->next = node;
}
/* 曾经的两个错误：
   1) if (*pphead = pos) 用赋值代替比较，条件恒真，整条链表被置空；
   2) 删除头结点时把 *pphead 置 NULL，后面的结点全部丢失，
      应先 *pphead = pos->next 再 free(pos)。 */
void SllPopNodePos(SllNode** pphead, SllNode* pos) {
	assert(pphead);
	assert(pos);
	assert(*pphead);
	if (*pphead == pos) {
		*pphead = pos->next;
		free(pos);
		
		return;
	}
	SllNode* cur = *pphead;
	while(cur != NULL && cur->next!=pos){
		cur = cur->next;
	}
	if (cur == NULL) {
		return;
	}
	cur->next = pos->next;
	free(pos);
}
void SllModifyNodePos(SllNode* pos,int x) {
	assert(pos);
	pos->val = x;

}
