# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToAnyOf
Defined in header [<xieite/concepts/ConvertibleToAnyOf.hpp>](../../../include/xieite/concepts/ConvertibleToAnyOf.hpp)

&nbsp;

## Description
Specifies that a type can be converted to at least one of several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToAnyOf = (... || std::convertible_to<Source, Targets>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/ConvertibleToAnyOf.hpp>

template<xieite::concepts::ConvertibleToAnyOf<bool, char, int>>
void test() {
    std::cout << "foo\n";
}

template<typename>
void test() {
    std::cout << "bar\n";
}

int main() {
    test<char>();
    test<std::string>();
}
```
Output:
```
foo
bar
```
