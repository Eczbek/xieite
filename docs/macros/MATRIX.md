# XIEITE_MATRIX
Defined in header `<xieite/macros/MATRIX.hpp>`

<br/>

Creates a multidimensional vector matrix.

<br/><br/>

## Definition
```cpp
#define XIEITE_MATRIX(unsignedInteger, type) XIEITE_REPEAT(std::vector<, unsignedInteger) type XIEITE_REPEAT(>, unsignedInteger)
```

<br/><br/>

## Example
```cpp
#include <xieite/macros/MATRIX.hpp>

int main() {
	XIEITE_MATRIX(3, int) matrix;
}
```
Result:
```cpp
int main() {
	std::vector<std::vector<std::vector<int>>> matrix;
}
```
