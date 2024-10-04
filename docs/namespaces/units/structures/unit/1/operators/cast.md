# [xieite](../../../../../../xieite.md)\:\:[units](../../../../../units.md)\:\:[Unit<type, toBase, fromBase>](../../../../unit.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:units.Unit](../../../../../../../src/units/unit.cpp)

&nbsp;

## Description
Casts one unit to another of the same type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto otherToBase, auto otherFromBase>
[[nodiscard]] explicit(false) constexpr operator xieite::units::Unit<type, otherToBase, otherFromBase>() const noexcept;
```

&nbsp;

## [Example](../../../../unit.md#Example)
