#define  _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"
bool initseqlist(slist* sl) {
	assert(sl);
	sl->list = NULL;
	sl->capacity = 0;
	sl->size = 0;
	datatype* ptr = (datatype*)malloc(sizeof(datatype) * initcapacity);
	if (ptr == NULL) {
		perror("malloc");
		return false;
	}
	sl->list = ptr;
	sl->capacity = initcapacity;
	return true;
}
bool seqlistcheckcapacity(slist* sl) {
	assert(sl);
	
	if (sl->capacity > sl->size) {
		return true;
	}
	int newcap = (sl->capacity == 0) ? initcapacity: sl->capacity * 2;
	
		
		datatype* ptr = (datatype*)realloc(sl->list, sizeof(datatype) * (newcap));
		if (ptr == NULL) {
			perror("realloc");
			return false;
		}
		sl->list = ptr;
		
		sl->capacity *= 2;
		return true;
	
	
		
}
void seqlistdestroy(slist* sl) {
	assert(sl);
	free(sl->list);
	sl->list = NULL;
	sl->size = 0;
	sl->capacity = 0;
}
bool slpushfront(slist* sl, datatype x) {
	assert(sl);
	if (!seqlistcheckcapacity(sl)) {
		return false;
	}
	
	for (int i = sl->size; i >0; i--) {
		sl->list[i] = sl->list[i-1];
		
	}
	sl->list[0] = x;
	sl->size++;
	return true;
}
void slpopfront(slist*sl) {
	assert(sl);
	assert(sl->size != 0);
	
	for (int i = 1; i < sl->size; i++)
	{
		sl->list[i - 1] = sl->list[i];
	}
	sl->size--;
}
bool slpushback(slist* sl,datatype x) {
	assert(sl);
	if (!seqlistcheckcapacity(sl)) {
		return false;
	}
	sl->list[sl->size] = x;
	sl->size++;
	return true;
}
void slpopback(slist* sl) {
	assert(sl);
	assert(sl->size != 0);
	sl->size--;
}
bool slpush(slist* sl,datatype x,int pos) {
	assert(sl);
	assert(pos <= sl->size && pos >= 0);
	if (!seqlistcheckcapacity(sl)) {
		return false;
	}
	for (int i = sl->size; i > pos; i--) {
		sl->list[i] = sl->list[i - 1];
	}
	sl->list[pos] = x;
	sl->size++;
	return true;
}
void slpop(slist* sl, int pos) {
	assert(sl);
	assert(pos < sl->size && pos >= 0);
	assert(sl->size != 0);
	for (int i = pos+1; i < sl->size; i++) {
		sl->list[i-1] = sl->list[i];
	}
	sl->size--;
}
int slsearch(slist* sl,int x) {
	assert(sl);
	for (int i = 0; i < sl->size; i++) {
		if (sl->list[i] == x) {
			return i;
		}

	}
	printf("Œ¥’“µΩ\n");
	return -1;

}
void slprintf(slist* sl) {
	assert(sl);
	for (int i = 0; i < sl->size; i++) {
		printf("%d  ", sl->list[i]);

	}
	printf("\n");
}
