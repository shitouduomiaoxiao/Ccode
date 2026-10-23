# 10.23 练习：中位数 & 无重复字符最长子串

两道 LeetCode 题的函数实现，代码见 [`Project1/源.c`](Project1/源.c)。

| 函数 | 对应题目 | 思路 |
| --- | --- | --- |
| `findMedianSortedArrays` | LeetCode 4. 寻找两个正序数组的中位数 | 合并到临时数组 → `qsort` 升序 → 按下标奇偶取中位数 |
| `lengthOfLongestSubstring` | LeetCode 3. 无重复字符的最长子串 | 枚举每个起点，向后扩展并用 128 个桶记录字符是否出现 |

## 当前状态：MSVC 下编译不通过

`源.c` 原本只有一行 `#define`，代码是从 Visual Studio 的自动恢复缓存
（`%LOCALAPPDATA%\Microsoft\VisualStudio\BackupFiles\Project1\~AutoRecover.源.c`）里找回并写回的。

用 `cl /c` 单独编译的实际报错：

```
src.c(5):  error C2057: 应输入常量表达式
src.c(5):  error C2466: 不能分配常量大小为 0 的数组
src.c(5):  error C2133: "num3": 未知的大小
src.c(12): error C2143: 语法错误: 缺少";"(在"{"的前面)
src.c(13): error C2065: "e1": 未声明的标识符
src.c(15): warning C4013: "qsort"未定义；假设外部返回 int
src.c(25): warning C4013: "strlen"未定义；假设外部返回 int
```

对应 4 个问题与改法：

| # | 问题 | 改法 |
| --- | --- | --- |
| 1 | `int num3[sz];` 变长数组（VLA），**MSVC 不支持** | 改用 `int* num3 = (int*)malloc(sizeof(int) * sz);`，用完 `free` |
| 2 | `int cmp(...)` 定义在函数**内部**（嵌套函数），标准 C 不允许 | 把 `cmp` 提到文件作用域（在所有函数外） |
| 3 | 没有 `#include <stdlib.h>` / `<string.h>` | 文件开头补上（`qsort`/`malloc`/`strlen` 需要） |
| 4 | 没有 `main()`，且工程里没包含 `源.c` | 写测试用的 `main()`，并把文件加进工程（当前 `.vcxproj` 的 ItemGroup 是空的） |

## 另外两个正确性/健壮性问题

- `lengthOfLongestSubstring()` 里 `unsigned int c = (unsigned int)s[j];`：
  `char` 若为有符号且字节值 >127（中文/UTF-8 场景），转 `unsigned int` 会得到巨大的下标，
  **越界写 `chek[128]`**。应改为 `unsigned char c = (unsigned char)s[j];` 并把桶开到 256。
- 中位数偶数分支 `(float)(a + b) / 2` 建议写成 `(a + b) / 2.0`，语义更清楚。

## 参考改法（中位数部分）

```c
#include <stdlib.h>
#include <string.h>

static int cmp_int(const void* e1, const void* e2) {   /* 提到文件作用域 */
    return *(const int*)e1 - *(const int*)e2;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sz = nums1Size + nums2Size;
    int* num3 = (int*)malloc(sizeof(int) * sz);
    if (num3 == NULL) return 0.0;
    memcpy(num3, nums1, sizeof(int) * nums1Size);
    memcpy(num3 + nums1Size, nums2, sizeof(int) * nums2Size);
    qsort(num3, sz, sizeof(int), cmp_int);
    double med = (sz % 2 == 0)
        ? (num3[sz / 2] + num3[sz / 2 - 1]) / 2.0
        : num3[sz / 2];
    free(num3);
    return med;
}
```

## 工程

VS 打开 `Project1/Project1.sln`。注意当前 `.vcxproj` **没有把 `源.c` 加入编译**，
需要在解决方案资源管理器里右键"添加 → 现有项"选中 `源.c`，否则生成的是一个空工程。
