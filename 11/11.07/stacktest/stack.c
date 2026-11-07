#define  _CRT_SECURE_NO_WARNINGS
#include"stack.h"
void STInit(ST* st) {
	Datatype* tmp = (Datatype*)malloc(sizeof(Datatype) * CAPACITE);
	if (tmp == NULL) {
		perror("malloc");
		return;
	}
	st->a = tmp;
	st->capacity = CAPACITE;
	st->top = 0;
}
void STDestroy(ST* st) {
	free(st->a);
	st->a = NULL;
	st->capacity = 0;
	st->top = 0;

}
bool STEtmpy(ST* st) {
	return st->top == 0;
}
void STpush(ST* st, Datatype x) {
	assert(st);
	if (st->top == st->capacity) {
		Datatype* tmp = (Datatype*)realloc(st->a, sizeof(Datatype) * st->capacity* 2);
		if (tmp == NULL) {
			perror("realloc");
			return;
		}
		 st->a =tmp;
		st->capacity *= 2;
	}
	st->a[st->top] = x;
	st->top++;
}
void STpop(ST* st) {
	assert(st);
	assert(!STEtmpy(st));
	st->top--;
}
Datatype StackTop(ST* st) {
	assert(st);
	assert(!STEtmpy(st));
	return st->a[st->top - 1];
}