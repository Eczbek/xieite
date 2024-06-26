# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:OutputStream\<\>
Defined in header [<xieite/concepts/output_stream.hpp>](../../../include/xieite/concepts/output_stream.hpp)

&nbsp;

## Description
Specifies that a type is `std::ostream` or derives from it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept OutputStream = std::same_as<std::remove_cvref_t<Type_>, std::ostream> || std::derived_from<std::remove_cvref_t<Type_>, std::ostream>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/output_stream.hpp"

int main() {
    std::println("{}", xieite::concepts::OutputStream<decltype(std::cin)>);
    std::println("{}", xieite::concepts::OutputStream<decltype(std::cout)>);
}
```
Output:
```
false
true
```
