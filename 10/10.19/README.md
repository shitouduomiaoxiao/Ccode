# 10.19 动态内存练习

C 语言动态内存开辟的三种方式，代码见 [`Project1/源.c`](Project1/源.c)（以注释形式保留，逐个取消注释后编译验证）。

## 三种方式对比

| 函数 | 原型 | 特点 |
| --- | --- | --- |
| `malloc` | `void* malloc(size_t)` | 只开辟空间，**不初始化**，内容是随机值 |
| `calloc` | `void* calloc(n, size)` | 开辟 n×size 字节并**全部初始化为 0** |
| `realloc` | `void* realloc(void* p, size_t)` | 调整已有空间大小；`p=NULL` 时等价于 `malloc` |

## 要点

1. **每次都要判空**：分配失败返回 `NULL`，直接解引用会崩溃
   ```c
   char* p = (char*)malloc(40);
   if (p == NULL) { perror("malloc"); return 1; }
   ```
2. **用临时指针接 `realloc` 的返回值**，直接 `p = realloc(p, n)` 若失败会丢失原指针，造成内存泄漏
3. **用完必须 `free`，并置 `NULL`**，避免野指针与重复释放
4. `printf(pc)` 打印未初始化的 `malloc` 内容会读到乱码，`calloc` 则输出空串（全 0）

## 工程

Visual Studio 打开 `Project1/Project1.sln`，x64/Debug 生成运行。
