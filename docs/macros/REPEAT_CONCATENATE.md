# XIEITE_REPEAT_CONCATENATE
Defined in header `<xieite/macros/REPEAT_CONCATENATE.hpp>`

<br/>

Repeats the concatenation of an expression with itself. Maximum repetition count is 2047.

<br/><br/>

## Declarations
```cpp
#define XIEITE_REPEAT_CONCATENATE(expression, unsignedInteger) \
	XIEITE_CONCATENATE(XIEITE_REPEAT_CONCATENATE_, unsignedInteger)(expression)
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/REPEAT_CONCATENATE.hpp>

int main() {
	std::cout << XIEITE_REPEAT_CONCATENATE(5, 3) << '\n';
}
```
Output:
```
555
```
