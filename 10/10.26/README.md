# 10.26 练习：my_memmove（内存重叠拷贝）

自己实现 `memmove`，重点处理**源和目标内存重叠**的情况。

## 实现思路

```c
if (dst <= src) {
    /* 目标在源左边（或重合）：从低地址往高地址逐字节复制，不会覆盖还没读的源数据 */
    while (count--) { *(char*)dst = *(char*)src; dst++; src++; }
} else {
    /* 目标在源右边：必须从高地址往低地址倒着复制 */
    while (count--) { *((char*)dst + count) = *((char*)src + count); }
}
```

一句话：**重叠时拷贝方向要躲开自己**——往高地址搬就从后往前，往低地址搬就从前往后。
`memcpy` 不做这个判断，所以重叠时会踩踏；`memmove` 会判断。

## 运行结果

`main` 里把 `arr1[0..4]` 搬到 `arr1[2..6]`（20 字节 = 5 个 int，属于重叠）：

```
原数组: 1 2 3 4 5 6 7 8 9 0
拷贝后: 1 2 1 2 3 4 5 8 9 0
输出:   1212345890
```

## 当前编译警告

```
源.c(32,1): warning C4715: "my_memmove": 不是所有的控件路径都返回值
```

原因：`return ret;` 只写在 `else if (dst > src)` 分支里，`dst <= src` 那条路径末尾没有返回值 →
函数返回的是**未定义值**（本次 main 没用到返回值，所以看不出问题）。

**改法**：把 `return ret;` 挪到函数最外层末尾，删掉分支里的那个：

```c
void* my_memmove(void* dst, void* src, int count) {
    void* ret = dst;
    if (dst <= src) {
        while (count--) { *(char*)dst = *(char*)src; dst = (char*)dst + 1; src = (char*)src + 1; }
    } else {
        while (count--) { *((char*)dst + count) = *((char*)src + count); }
    }
    return ret;          /* ← 统一在这里返回 */
}
```

## 还可改进的地方

| 项 | 现状 | 建议 |
| --- | --- | --- |
| `count` 类型 | `int` | 应为 `size_t`（与标准库一致，避免负数） |
| `src` 限定 | `void*` | 源不该被改，应为 `const void*` |
| 重叠判据 | `dst <= src` | 严谨写法：`dst > src && (char*)dst < (char*)src + count` 才反向，其余正向 |
| 注释掉的 `main` | 循环里误放了 `return 0;` | 保留作对照时建议删掉，免得误导 |

## 工程

VS 打开 `Project1/Project1.sln`，`x64 / Debug` 生成运行，输出 `1212345890`。
