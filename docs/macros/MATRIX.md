# [`XIEITE`](../../docs/macros.md)`_MATRIX`
Defined in header [`<xieite/macros/MATRIX.hpp>`](../../include/xieite/macros/MATRIX.hpp)

<br/>

Creates a multidimensional vector matrix.

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE_MATRIX(type, dimensions) \
	XIEITE_REPEAT(std::vector<, dimensions) type XIEITE_REPEAT(>, dimensions)
```
### Parameters
- `type` - Any type
- `dimensions` - An unsigned 8-bit value

<br/><br/>

## Example
```cpp
#include <xieite/macros/MATRIX.hpp>

int main() {
	XIEITE_MATRIX(int, 3) matrix;
}
```
Result:
```cpp
int main() {
	std::vector<std::vector<std::vector<int>>> matrix;
}
```
