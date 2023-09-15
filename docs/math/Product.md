# [xieite](../xieite.md)\:\:[math](../math.md)\:\:Product
Defined in header [<xieite/math/Product.hpp>](../../include/xieite/math/Product.hpp)

&nbsp;

## Description
Intended for storing the product of two unsigned integers in two parts.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::unsigned_integral UnsignedInteger>
struct Product {
    UnsignedInteger lower;
    UnsignedInteger upper;

    constexpr Product(UnsignedInteger, UnsignedInteger) noexcept;
};
```
##### Member variables
- lower
- upper
##### Member functions
- [Product](./Product/1/operators/constructor.md)
