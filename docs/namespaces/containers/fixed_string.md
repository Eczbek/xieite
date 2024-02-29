# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedString
Defined in header [<xieite/containers/fixed_string.hpp>](../../../include/xieite/containers/fixed_string.hpp)

&nbsp;

## Description
Stores a fixed-size string.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t characters>
struct FixedString {
	char data[characters + 1];

	template<std::size_t otherCharacters>
	constexpr FixedString(const char (&)[otherCharacters]) noexcept;

	static constexpr std::size_t size() noexcept;

	constexpr std::string_view view() const noexcept;
};
```
##### Member variables
- data
##### Member functions
- [FixedString](./structures/fixed_string/1/operators/constructor.md)
- [size](./structures/fixed_string/1/size.md)
- [view](./structures/fixed_string/1/view.md)

&nbsp;

### Deduction guides
```cpp
template<std::size_t characters>
FixedString(char const (&)[characters]) -> FixedString<characters - 1>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <utility>
#include "xieite/containers/fixed_string.hpp"

int main() {
    constexpr xieite::containers::FixedString<std::string_view, int, 4> map {
        { "foo", 1 },
        { "bar", 2 },
        { "baz", 3 },
        { "qux", 4 }
    };

    for (auto [key, value] : map) {
        std::println("{}: {}", key, value);
    }
}
```
Output:
```
foo: 1
bar: 2
baz: 5
qux: 4
```