# [XIEITE](../macros.md)_STRINGIFY
Defined in header [<xieite/macros/STRINGIFY.hpp>](../../include/xieite/macros/STRINGIFY.hpp)

<br/>

Converts expressions to a string literally

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE_STRINGIFY(...) \
	XIEITE_INTERNAL_STRINGIFY(__VA_ARGS__)
```
### Parameters
- `...` - Any expressions

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/STRINGIFY.hpp>

int main() {
	std::cout << XIEITE_STRINGIFY(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
