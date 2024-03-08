# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:String
Defined in header [<xieite/concepts/string.hpp>](../../../include/xieite/concepts/string.hpp)

&nbsp;

## Description
Specifies that a type is a specialization of `std::basic_string` or `std::pmr::basic_string`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept String = xieite::concepts::SpecializationOfAny<Type, std::basic_string, std::pmr::basic_string>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/concepts/string.hpp"

int main() {
    std::println("{}", xieite::concepts::String<std::string>);
    std::println("{}", xieite::concepts::String<std::wstring>);
    std::println("{}", xieite::concepts::String<std::u8string>);
    std::println("{}", xieite::concepts::String<std::u16string>);
    std::println("{}", xieite::concepts::String<std::u32string>);
    std::println("{}", xieite::concepts::String<std::pmr::string>);
    std::println("{}", xieite::concepts::String<std::pmr::wstring>);
    std::println("{}", xieite::concepts::String<std::pmr::u8string>);
    std::println("{}", xieite::concepts::String<std::pmr::u16string>);
    std::println("{}", xieite::concepts::String<std::pmr::u32string>);
    std::println("{}", xieite::concepts::String<void>);
}
```
Output:
```
true
true
true
true
true
true
true
true
true
true
false
```
