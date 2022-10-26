# GCUFL_MATRIX
Declared in `<xieite/macros/MATRIX.hpp>`
```cpp
#define GCUFL_MATRIX(d, t) GCUFL_REPEAT(std::vector<, d) t GCUFL_REPEAT(>, d)
```
Creates a vector matrix with `d` dimensions, of type `t`.
## Example
```cpp
#include <xieite/macros/MATRIX.hpp>

int main() {
	GCUFL_MATRIX(3, int)
}
```
Preprocessor output (without headers):
```
int main() {
	std::vector< std::vector< std::vector< int > > >
}
```
