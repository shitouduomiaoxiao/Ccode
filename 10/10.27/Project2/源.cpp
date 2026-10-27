#define  _CRT_SECURE_NO_WARNINGS
#include<string.h>
int main() {
    memcpy();
	return 0;
}
//去除数组数值
int removeElement(int* nums, int numsSize, int val) {
    int* fast = nums;
    int* slow = nums;
    int k = 0;
    while (numsSize--) {
        if (*fast != val) {
            *slow = *fast;
            slow++;
            k++;
        }
        fast++;
    }

    return k;
}
//数组轮转
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    int* numsout = malloc(numsSize * sizeof(int));
    if (numsout == NULL) {
        return;
    }
    memcpy(numsout, nums + numsSize - k, k * sizeof(int));
    memcpy(numsout + k, nums, (numsSize - k) * sizeof(int));
    memcpy(nums, numsout, numsSize * sizeof(int));
    free(numsout);
}
//寻找消失数
int missingNumber(int* nums, int numsSize) {


    int ret = 0;
    for (int i = 0; i < numsSize; i++) {

        ret ^= nums[i];
    }
    for (int i = 0; i <= numsSize; i++) {
        ret ^= i;
    }
    return ret;
}
