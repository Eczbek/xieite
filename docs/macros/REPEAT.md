# GCUFL_REPEAT
Declared in `<xieite/macros/REPEAT.hpp>`

<br/>

Repeats an expression literally.

<br/><br/>

```cpp
#define GCUFL_REPEAT(x, n) GCUFL_CONCAT(GCUFL_REPEAT_, n)(x)
```

<br/><br/>

## Example
See `GCUFL_MATRIX`.
