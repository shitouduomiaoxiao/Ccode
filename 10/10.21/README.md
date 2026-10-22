# 10.21 链表练习：两数相加

递归版「两数相加」（LeetCode 2）：两个非空链表倒序存储两个非负整数，每位相加，进位向高位传递。

## 核心实现

```c
struct ListNode* addTwo(struct ListNode* l1, struct ListNode* l2, int carry) {
    if (l1 == NULL && l2 == NULL && carry == 0) return NULL;   /* 递归出口 */

    int s = carry;
    if (l1) { s += l1->val; l1 = l1->next; }
    if (l2) { s += l2->val; l2 = l2->next; }

    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val  = s % 10;                       /* 本位 */
    node->next = addTwo(l1, l2, s / 10);       /* 高位递归，carry 传下去 */
    return node;
}
```

递归的妙处：`carry` 作为参数一路往下传，不用额外变量，也不用手动搬运指针。

## 当前待完善（尚未通过编译）

1. **第一行 `Definition for singly - linked list.` 缺少 `//` 注释符** → 语法错误
2. **缺少头文件**：`malloc` 需要 `#include <stdlib.h>`
3. **`.cpp` 里 `malloc` 返回 `void*`**，赋给 `struct ListNode*` 需强制转换：
   `(struct ListNode*)malloc(sizeof(struct ListNode))`
4. **没有 `main()`** → 链接失败（LeetCode 只提交函数，本地跑要自己写测试）
5. `addTwoNumbers()` 是对外接口，内部转调 `addTwo(l1, l2, 0)`

## 本地测试建议

```c
#include <stdio.h>
#include <stdlib.h>

struct ListNode* build(int* a, int n);   /* 用数组造链表 */
void printList(struct ListNode* h);
void freeList(struct ListNode* h);

int main(void) {
    int a[] = {2, 4, 3}, b[] = {5, 6, 4};   /* 342 + 465 = 807 */
    struct ListNode* r = addTwoNumbers(build(a, 3), build(b, 3));
    printList(r);                            /* 输出 7 0 8 */
    return 0;
}
```

## 工程

VS 打开 `Project1/Project1.sln`。
