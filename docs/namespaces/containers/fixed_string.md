# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedString\<\> \{\}
Defined in fragment [xieite:containers.FixedString](../../../src/containers/fixed_string.cpp)

&nbsp;

## Description
Stores a fixed-size string.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t characters, typename Character = char>
struct FixedString {
    static constexpr std::size_t size = characters;
    std::array<Character, characters> data;

    constexpr FixedString(const Character(&)[characters]) noexcept;

    template<std::ranges::input_range Range>
    requires(std::same_as<std::ranges::range_value_t<Range>, Character>)
    constexpr FixedString(Range&&)
    noexcept(xieite::concepts::NoThrowOperableRange<Range>);

    constexpr std::string_view view() const noexcept;
};
```
- [FixedString\(\)](./structures/fixed_string/1/operators/constructor.md)
- [view\(\)](./structures/fixed_string/1/view.md)
- data
- size

&nbsp;

### Deduction guides
```cpp
template<auto characters, typename Character>
FixedString(char Character(&)[characters]) -> xieite::containers::FixedString<characters, Character>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

template<xieite::containers::FixedString string>
void foo() {
    std::println("{}", string.view());
}

int main() {
    foo<"abc">();
    foo<"xyz">();
}
```
Output:
```
abc
xyz
```
