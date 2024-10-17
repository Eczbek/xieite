# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Counter\<\> \{\}
Defined in fragment [xieite:functors.Counter](../../../src/functors/counter.cpp)

&nbsp;

## Description
A compile-time counter thingamabob. Technically not ill-formed ([yet](https://www.open-std.org/jtc1/sc22/wg21/docs/cwg_active.html#2118)) but causes wonky behavior if used in template constraints. In any case, this hack currently works on major compilers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto identifier = [] {}, std::integral Integral = std::size_t>
struct Counter {
    template<auto = [] {}>
    static consteval Integral get() noexcept;

    template<auto = [] {}>
    static consteval Integral advance() noexcept;

    template<auto = [] {}>
    static consteval Integral next() noexcept;
};
```
- [get\<\>\(\)](./structures/counter/1/get.md)
- [advance\<\>\(\)](./structures/counter/1/advance.md)
- [next\<\>\(\)](./structures/counter/1/next.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

using C = xieite::functors::Counter<>;
static_assert(C::get() == 0);
static_assert(C::advance() == 0);
static_assert(C::advance() == 1);
static_assert(C::advance() == 2);
static_assert(C::get() == 3);
static_assert(C::next() == 4);
static_assert(C::next() == 5);

int main() {}
```
