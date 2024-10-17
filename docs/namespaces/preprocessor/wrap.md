# [XIEITE](../../macros.md)\_WRAP\(\)
Defined in header [<xieite/wrap.hpp>](../../../include/xieite/wrap.hpp)

&nbsp;

## Description
A helper macro which wraps arguments in parentheses.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_WRAP(...) (__VA_ARGS__)
```

&nbsp;

## Example
```cpp
#include <xieite/wrap.hpp>

XIEITE_WRAP(1, 2, 3)
```
Preprocessor output:
```
(1, 2, 3)
```
