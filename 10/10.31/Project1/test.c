#define  _CRT_SECURE_NO_WARNINGS
#include"SinglyLinkList.h"
SllNode* list = NULL;
int testsll() {
	SllPushNodeFront(&list,2);
	Sllprintf(list);
	SllPushNodeBack(&list, 3);
	Sllprintf(list);
	SllNode* pos = SllSearch(list, 2);
	SllPushNodePos(&list, pos, 5);
	Sllprintf(list);
	SllModifyNodePos(pos, 8);
	Sllprintf(list);
	SllPopNodePos(&list, pos);
	Sllprintf(list);



	return 0;

}
int main(){
	testsll();

return 0;
}
