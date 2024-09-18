# [XIEITE](../../macros.md)\_CHECK\(\)
Defined in header [<xieite/check.hpp>](../../../include/xieite/check.hpp)

&nbsp;

## Description
A helper macro that does magic. See definition for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_CHECK(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/check.hpp>
#include <xieite/probe.hpp>

XIEITE_CHECK(abcdef)
XIEITE_CHECK(XIEITE_PROBE(~))
```
Preprocessor output:
```
0
1
```
