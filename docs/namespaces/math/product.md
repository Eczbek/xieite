# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Product
Defined in header [<xieite/math/product.hpp>](../../../include/xieite/math/product.hpp)

&nbsp;

## Description
Intended for storing the product of two unsigned integers in two parts.

&nbsp;

## Synopsis
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
- [Product](./structures/product/1/operators/constructor.md)
