# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:IntegerStringComponents
Defined in header [<xieite/math/integer_string_components.hpp>](../../../include/xieite/math/integer_string_components.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
struct IntegerStringComponents {
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char negative = '-';
    char positive = '+';
    char point = '.';
    char exponent = 'e';

    constexpr IntegerStringComponents();

    constexpr IntegerStringComponents(std::string_view, char, char, char, char);
};
```
##### Member variables
- digits
- negative
- positive
- point
- exponent
##### Member functions
- [IntegerStringComponents](./structures/integer_string_components/1/operators/constructor.md)
