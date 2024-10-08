# [XIEITE](../../macros.md)\_EACH\(\)
Defined in header [<xieite/each.hpp>](../../../include/xieite/each.hpp)

&nbsp;

## Description
Repeats a macro for every argument.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_EACH(macro_, ...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/each.hpp>

XIEITE_EACH(F, a, b, c, d, e, f);
```
Preprocessor output:
```
F(a) F(b) F(c) F(d) F(e) F(f)
```
