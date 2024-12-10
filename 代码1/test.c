

//例；检验一个数是不是偶数
//if语句的双分支结构
#include <stdio.h>

int main() {
    int num;
    printf("请输入一个整数：");
    scanf_s("%d", &num);

    if (num % 2 == 0) {
        printf("%d 是偶数。\n", num);
    }
    else {
        printf("%d 不是偶数。\n", num);
    }

    return 0;
}







































