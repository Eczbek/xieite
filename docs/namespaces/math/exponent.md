# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Exponent\<\> \{\}
Defined in fragment [xieite:functors.Exponent](../../../src/functors/exponent.cpp)

&nbsp;

## Description
An exponent operator thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
struct Exponent {
private:
    struct Intermediate;

public:
    constexpr Exponent(Arithmetic) noexcept;

    template<xieite::concepts::Arithmetic OtherArithmetic>
    explicit(false) constexpr operator std::common_type_t<Arithmetic, OtherArithmetic>() const noexcept;

    constexpr xieite::math::Exponent<Arithmetic>::Intermediate operator*() const noexcept;
};
```
- [Intermediate \{\}](./structures/exponent/1/intermediate.md)
- [Exponent\(\)](./structures/exponent/1/operators/constructor.md)
- [operator typename\<\>\(\)](./structures/exponent/1/operators/cast.md)
- [operator\*\(\)](./structures/exponent/1/operators/multiply.md)

&nbsp;

### Deduction guides
```cpp
template<typename Type>
Exponent(Type) -> xieite::math::Exponent<Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", 3 ** xieite::math::Exponent(4));
}
```
Output:
```
81
```
