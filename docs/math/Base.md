# [xieite](../xieite.md)\:\:[math](../math.md)\:\:Base
Defined in header [<xieite/math/Base.hpp>](../../include/xieite/math/Base.hpp)

&nbsp;

## Description
Intended for storing information about a numeral system.

&nbsp;

## Synopses
#### 1)
```cpp
struct Base {
    int radix;
    char negativeSign;
        
    constexpr Base(int, std::string_view = "0123456789abcdefghijklmnopqrstuvwxyz", char = '-', bool = false) noexcept;
    
    constexpr char digit(std::size_t) const noexcept;
    
    constexpr std::size_t position(char) const noexcept;
};
```
##### Member variables
- radix
- negativeSign
##### Member functions
- [Base](./Base/1/operators/constructor.md)
- [digit](./Base/1/digit.md)
- [position](./Base/1/position.md)
