# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:StringView
Defined in header [<xieite/concepts/string_view.hpp>](../../../include/xieite/concepts/string_view.hpp)

&nbsp;

## Description
Specifies that a type is a specialization of `std::basic_string_view`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept StringView = xieite::concepts::SpecializationOf<Type, std::basic_string_view>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string_view>
#include "xieite/concepts/string_view.hpp"

int main() {
    std::println("{}", xieite::concepts::StringView<std::string_view>);
    std::println("{}", xieite::concepts::StringView<std::wstring_view>);
    std::println("{}", xieite::concepts::StringView<std::u8string_view>);
    std::println("{}", xieite::concepts::StringView<std::u16string_view>);
    std::println("{}", xieite::concepts::StringView<std::u32string_view>);
    std::println("{}", xieite::concepts::StringView<void>);
}
```
Output:
```
true
true
true
true
true
false
```
