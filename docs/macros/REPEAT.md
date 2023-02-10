# XIEITE_REPEAT
Declared in `<xieite/macros/REPEAT.hpp>`

<br/>

Repeats an expression literally.

<br/><br/>

## Definition
```cpp
#define XIEITE_REPEAT(x, n) XIEITE_CONCAT(XIEITE_REPEAT_, n)(x)
```
