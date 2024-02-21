# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToAny
Defined in header [<xieite/concepts/convertible_to_any.hpp"](../../../include/xieite/concepts/convertible_to_any.hpp)

&nbsp;

## Description
Specifies that a type can be converted to at least one of several other types. Passing no target types evaluates to `true`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToAny = (... || std::convertible_to<Source, Targets>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/convertible_to_any.hpp"

struct Nope {};

template<xieite::concepts::ConvertibleToAny<bool, char, int>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<char>();
    test<Nope>();
}
```
Output:
```
yep
nope
```
