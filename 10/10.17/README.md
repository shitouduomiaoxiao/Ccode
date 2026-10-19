# 10.17 通讯录项目 · 版本记录

课程练习工程（自动控制原理Ⅱ / C 语言程序设计练习），按日期迭代，**新旧版本全部保留**。

| 版本 | 日期 | 目录 | 概要 |
| --- | --- | --- | --- |
| **v3（最新）** | 2026-10-19 | [`contact/`](contact/) | **动态内存版**：`calloc / realloc / free`，容量按需增长 |
| v2 | 2026-10-18 | [`v2-20261018/`](v2-20261018/) | 静态数组版修复：删除/排序逻辑、`const` 签名、`qsort` 按姓名排序 |
| v1 | 2026-10-17 | [`v1-20261017/`](v1-20261017/) | 静态数组版初版：`peo data[100]` + `int sz` |

## v3（动态版）关键变化

```c
/* v1 / v2：静态数组 */
typedef struct contact { peo data[peomax]; int sz; } con;

/* v3：动态扩容 */
typedef struct con { peo* data; int sz; int cap; } con;
```

- `initcon()`：`calloc(defsz=3, sizeof(peo))` 申请初始容量
- `add()`：`sz == cap` 时 `realloc(data, sizeof(peo) * (cap + inc_size))`，每次扩 2 个
- `freecon()`：退出前 `free(data)`，避免内存泄漏
- 静态版实现以注释形式保留在源码里，便于对照学习

## 编译运行

Visual Studio 2017+ 打开 `contact.sln`，`x64 / Debug` 生成运行；或命令行：

```bat
cl contact.c test.c /Fe:contact.exe
```

## 已知可改进项

- `serch()` 未判断 `SerByName()` 返回 `-1`（查不到时会用 -1 当前标）
- `scanf("%s")` 未限制宽度：建议 `%19s`（name）、`%4s`（sex）、`%99s`（post）、`%12s`（tele）
- 输入菜单时若输入非数字，`scanf("%d")` 失败会反复打印菜单
