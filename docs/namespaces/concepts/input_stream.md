# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:InputStream\<\>
Defined in header [<xieite/concepts/input_stream.hpp>](../../../include/xieite/concepts/input_stream.hpp)

&nbsp;

## Description
Specifies that a type is `std::istream` or derives from it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept InputStream = std::same_as<std::remove_cvref_t<Type_>, std::istream> || std::derived_from<std::remove_cvref_t<Type_>, std::istream>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/input_stream.hpp"

int main() {
    std::println("{}", xieite::concepts::InputStream<decltype(std::cin)>);
    std::println("{}", xieite::concepts::InputStream<decltype(std::cout)>);
}
```
Output:
```
true
false
```
