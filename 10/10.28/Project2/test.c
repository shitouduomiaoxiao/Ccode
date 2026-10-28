#define  _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"
void testseqlist() {
	slist sl = { 0 };
	initseqlist(&sl);
	slpushfront(&sl, 1);
	slprintf(&sl);
	slpushfront(&sl, 2);
	slprintf(&sl);
	seqlistdestroy(&sl);


}
int main(void) {
	testseqlist();
	return 0;
}