# [xieite](../../../../../../xieite.md)\:\:[units](../../../../../units.md)\:\:[Unit<type, operations...>](../../../../unit.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:units.Unit](../../../../../../../src/units/unit.cpp)

&nbsp;

## Description
Casts one unit to another of the same type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto... otherOperations>
[[nodiscard]] explicit(false) constexpr operator xieite::units::Unit<type, otherOperations...>() const noexcept;
```

&nbsp;

## [Example](../../../../unit.md#Example)
