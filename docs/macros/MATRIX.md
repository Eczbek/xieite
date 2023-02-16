# XIEITE_MATRIX
Declared in `<xieite/macros/MATRIX.hpp>`

<br/>

Creates a vector matrix with `d` dimensions, of type `t`.

<br/><br/>

## Definition
```cpp
#define XIEITE_MATRIX(d, t) XIEITE_REPEAT(std::vector<, d) t XIEITE_REPEAT(>, d)
```

<br/><br/>

## Example
```cpp
#include <xieite/macros/MATRIX.hpp>

int main() {
	XIEITE_MATRIX(3, int)
}
```
Preprocessor output:
```cpp
int main() {
	std::vector< std::vector< std::vector< int > > >
}
```
