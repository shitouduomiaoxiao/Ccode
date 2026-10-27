# 10.27 练习：数组三题

代码见 [`Project2/源.cpp`](Project2/源.cpp)，三题都是 LeetCode 数组类经典题。

| 函数 | 题目 | 思路 | 复杂度 |
| --- | --- | --- | --- |
| `removeElement` | 27. 移除元素 | **快慢指针**：fast 扫描，不等于 val 就写回 slow | O(n) / O(1) |
| `rotate` | 189. 轮转数组 | 开临时数组，把后 k 个搬到前面再搬剩下的 | O(n) / O(n) |
| `missingNumber` | 268. 丢失的数字 | **异或**：`nums` 所有元素 ^ `0..n`，成对抵消只剩缺失值 | O(n) / O(1) |

## 三题的核心点

**移除元素**：慢指针 `slow` 只在新元素该写入的位置前进，`k` 就是最终长度；
不需要真的"删除"，把要保留的元素往前挤即可，所以能做到 O(1) 额外空间。

**轮转数组**：`k %= numsSize` 先处理 k 大于长度的情况，然后
`[后 k 个] + [前 n-k 个]` 拼起来写回原数组。

**丢失的数字**：异或的两个性质——`x ^ x = 0`、`x ^ 0 = x`。
把 `0..n` 全部异或一遍，再异或数组里的每个元素，出现两次的抵消为 0，
剩下的就是那个只出现一次的数。

## 当前编译状态：3 个错误

```
源.cpp(4,5):  error C2660: "memcpy": 函数不接受 0 个参数
源.cpp(26,20): error C3861: "malloc": 找不到标识符
源.cpp(33,5):  error C3861: "free": 找不到标识符
```

| # | 问题 | 改法 |
| --- | --- | --- |
| 1 | `main()` 里写了 `memcpy();`（无参数） | 删掉这行，或换成真正的测试代码 |
| 2 | 没有 `#include <stdlib.h>` | 文件开头补上（`malloc` / `free` 需要） |
| 3 | `.cpp` 里 `int* numsout = malloc(...)` | C++ 要求显式转换：`(int*)malloc(...)` |

补全后的 `main` 建议这样写：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* 移除元素 */
    int a[] = {3, 2, 2, 3};
    int k = removeElement(a, 4, 3);
    printf("removeElement: k=%d, ", k);
    for (int i = 0; i < k; i++) printf("%d ", a[i]);
    printf("\n");

    /* 轮转数组 */
    int b[] = {1, 2, 3, 4, 5, 6, 7};
    rotate(b, 7, 3);
    printf("rotate: ");
    for (int i = 0; i < 7; i++) printf("%d ", b[i]);
    printf("\n");

    /* 丢失的数字 */
    int c[] = {3, 0, 1};
    printf("missingNumber: %d\n", missingNumber(c, 3));
    return 0;
}
```

预期输出：

```
removeElement: k=2, 2 2
rotate: 5 6 7 1 2 3 4
missingNumber: 2
```

## 还需要注意

- `rotate()` 里 `k %= numsSize;` 当 `numsSize == 0` 时会除零 → 建议开头加 `if (numsSize <= 1) return;`
- 函数缺少"参数为空"检查：`removeElement`/`missingNumber` 传 `NULL` 会崩（LeetCode 保证非空，本地测试注意）

## 工程

VS 打开 `Project2/Project2.sln`，目录结构与前几天一致（工程名从 Project1 变成了 Project2）。
