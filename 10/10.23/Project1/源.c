#define  _CRT_SECURE_NO_WARNINGS
//中位数
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sz = nums1Size + nums2Size;
    int num3[sz];
    for (int i = 0; i < nums1Size; i++) {
        num3[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        num3[nums1Size + i] = nums2[i];
    }
    int cmp(const void* e1, const void* e2) {
        return(*(int*)e1) - (*(int*)e2);
    }
    qsort(num3, sz, sizeof(int), cmp);
    if (sz % 2 == 0) {
        return (float)(num3[sz / 2] + num3[sz / 2 - 1]) / 2;
    }

    return num3[sz / 2];
}
//寻找最长无重复字符串长度
int lengthOfLongestSubstring(char* s) {

    int sz = strlen(s);
    int best = 0;

    for (int i = 0; i < sz; i++) {
        int chek[128] = { 0 };
        int len = 0;
        for (int j = i; j < sz; j++) {
            unsigned int c = (unsigned int)s[j];
            if (chek[c]) {
                break;
            }
            chek[c] = 1;
            len++;


        }
        if (len > best) {
            best = len;
        }
    }
    return best;
}