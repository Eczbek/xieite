# [XIEITE](../macros.md)\_CONCATENATE
Defined in header [<xieite/macros/CONCATENATE.hpp>](../../include/xieite/macros/CONCATENATE.hpp)

<br/>

Concatenates expressions literally

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE__CONCATENATE(first, second) XIEITE_INTERNAL_CONCATENATE(first, second)
```
### Parameters
- `first` - Any expression
- `second` - Any expression

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/CONCATENATE.hpp>

int main() {
	std::cout << (XIEITE__CONCATENATE(4, 5) + 1) << '\n';
}
```
Output:
```
46
```
