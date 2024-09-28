# [XIEITE](../../macros.md)\_SEQUENCE...\(\)
Defined in header [<xieite/sequence.hpp>](../../../include/xieite/sequence.hpp)

&nbsp;

## Description
Expands to a lambda taking a `std::integer_sequence` which is immediately called. See definitions for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_SEQUENCE(index_, size_, ...) /* ... */
```
Captures `&`
#### 2)
```cpp
#define XIEITE_SEQUENCE_CAPTURE(captures_, index_, size_, ...) /* ... */
```
`captures_` may optionally be wrapped in parentheses
#### 3)
```cpp
#define XIEITE_SEQUENCE_TYPE(index_, size_, ...) /* ... */
```
Captures nothing, body is in unevaluated context, expands to a type


&nbsp;

## Example
```cpp
#include <xieite/sequence.hpp>

import std;

int main() {
    XIEITE_SEQUENCE(i, 3, (..., std::println("{}", i)));
}
```
Output:
```
0
1
2
```
