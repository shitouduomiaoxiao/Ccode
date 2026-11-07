#define  _CRT_SECURE_NO_WARNINGS
#include"stack.h"
int main() {
	ST st;
	STInit(&st);
	STpush(&st, 1);
	STpush(&st, 2);
	STpush(&st, 3);
	STpush(&st, 4);
	while (!STEmpt(&st)) {
		printf("  %d", StackTop(&st));
		STpop(&st);
	}
	STDestroy(&st);

	return 0;
}