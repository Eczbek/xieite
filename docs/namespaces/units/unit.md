# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\:Unit\<\> \{\}
Defined in fragment [xieite:units.Unit](../../../src/units/unit.cpp)

&nbsp;

## Description
A base structure for defining units.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::containers::FixedString type, auto... operations>
requires(/* ... */)
struct Unit {
    double value;

    template<auto... otherOperations>
    explicit(false) constexpr operator xieite::units::Unit<type, otherOperations...>() const noexcept;
};
```
- [operator typename\<\>\(\)](./structures/unit/1/operators/cast.md)
- value

&nbsp;

## Example
```cpp
import std;
import xieite;

using Base = xieite::units::Unit<"test">;

using Derived = xieite::units::Unit<"test", '/', 100.0>;
// i.e. to convert from Derived to Base, divide by 100

int main() {
    auto base = Base(1);
    auto derived = static_cast<Derived>(base);

    std::println("{} base", base.value);
    std::println("{} derived", derived.value);
}
```
Possible output:
```
1
100
```
