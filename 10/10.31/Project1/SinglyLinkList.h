#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct SinglyLinkList {
	int val;
	struct SinglyLinkList* next;

}SllNode;

	SllNode* creatsllnode(int );
	void SllPushNodeFront(SllNode**,int );
	void SllPopNodeFront(SllNode**);
	void SllPushNodeBack(SllNode**,int);
	void SllPopNodeBack(SllNode**);
	void Sllprintf(SllNode*);
	SllNode* SllSearch(SllNode*, int );
	void SllPushNodePos(SllNode**, SllNode*, int);
	void SllPopNodePos(SllNode**, SllNode*);
	void SllModifyNodePos( SllNode*,int);