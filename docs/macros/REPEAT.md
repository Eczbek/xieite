# XIEITE_REPEAT
Defined in header `<xieite/macros/REPEAT.hpp>`

<br/>

Repeats an expression literally. Maximum count is 2047.

<br/><br/>

## Declarations
```cpp
#define XIEITE_REPEAT(expression, unsignedInteger) XIEITE_CONCATENATE(XIEITE_REPEAT_, unsignedInteger)(expression)
```
