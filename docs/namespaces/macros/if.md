# [XIEITE](../../macros.md)\_IF...\(\)
Defined in header [<xieite/if.hpp>](../../../include/xieite/if.hpp)

&nbsp;

## Description
???

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_IF(condition_) XIEITE_IF_PRIMITIVE(XIEITE_BOOLEAN(condition_))
```
#### 2)
```cpp
#define XIEITE_IF_PRIMITIVE(boolean_) XIEITE_CONCATENATE_PRIMITIVE(XIEITE_IF_PRIMITIVE_, boolean_)
```
#### 3)
```cpp
#define XIEITE_IF_PRIMITIVE_0(then_, ...) __VA_ARGS__
```
#### 4)
```cpp
#define XIEITE_IF_PRIMITIVE_1(then_, ...) then_
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
