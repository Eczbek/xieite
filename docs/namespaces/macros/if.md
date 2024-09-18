# [XIEITE](../../macros.md)\_IF...\(\)
Defined in header [<xieite/if.hpp>](../../../include/xieite/if.hpp)

&nbsp;

## Description
???

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_IF($condition) XIEITE_IF_PRIMITIVE(XIEITE_BOOLEAN($condition))
```
#### 2)
```cpp
#define XIEITE_IF_PRIMITIVE($boolean) XIEITE_CONCATENATE_PRIMITIVE(XIEITE_IF_PRIMITIVE_, $boolean)
```
#### 3)
```cpp
#define XIEITE_IF_PRIMITIVE_0($then, ...) __VA_ARGS__
```
#### 4)
```cpp
#define XIEITE_IF_PRIMITIVE_1($then, ...) $then
```

&nbsp;

## Example
```cpp
#include <xieite/if.hpp>

XIEITE_IF(1)(abc, xyz)
XIEITE_IF(0)(abc, xyz)
```
Preprocessor output:
```
abc
xyz
```
