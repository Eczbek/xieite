# XIEITE_REPEAT
Declared in `<xieite/macros/REPEAT.hpp>`

<br/>

Repeats an expression literally.

<br/><br/>

## Definition
```cpp
#define XIEITE_REPEAT(expression, unsignedInteger) XIEITE_CONCATENATE(XIEITE_REPEAT_, unsignedInteger)(expression)
```
