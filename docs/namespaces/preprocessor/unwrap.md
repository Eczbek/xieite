# [XIEITE](../../macros.md)\_UNWRAP\(\)
Defined in header [<xieite/unwrap.hpp>](../../../include/xieite/unwrap.hpp)

&nbsp;

## Description
A helper macro which unwraps arguments from up to one set of parentheses.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_WRAP(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/unwrap.hpp>

XIEITE_UNWRAP(x)
XIEITE_UNWRAP((x))
XIEITE_UNWRAP(((x)))
```
Preprocessor output:
```

x
x
(x)
```
