# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedString<characters, Character>](../../../../fixed_string.md)\:\:FixedString\<\>\(\)
Defined in fragment [xieite:containers.FixedString](../../../../../../../src/containers/fixed_string.cpp)

&nbsp;

## Description
Constructs a `xieite::containers::FixedString<characters, Character>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr FixedString(const Character(&data)[characters]) noexcept;
```
#### 2)
```cpp
template<std::ranges::input_range Range>
requires(std::same_as<std::ranges::range_value_t<Range>, Character>)
constexpr FixedString(Range&& data)
noexcept(xieite::concepts::NoThrowOperableRange<Range>);
```

&nbsp;

## [Example](../view.md#Example)
