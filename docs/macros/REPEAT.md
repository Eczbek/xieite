# XIEITE_REPEAT
Defined in header `<xieite/macros/REPEAT.hpp>`

<br/>

Repeats an expression literally. Used in `XIEITE_MATRIX`.

<br/><br/>

## Definition
```cpp
#define XIEITE_REPEAT(expression, unsignedInteger) XIEITE_CONCATENATE(XIEITE_REPEAT_, unsignedInteger)(expression)
```
