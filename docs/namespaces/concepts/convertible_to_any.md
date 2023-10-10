# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToAny
Defined in header [<xieite/concepts/convertible_to_any.hpp>](../../../include/xieite/concepts/convertible_to_any.hpp)

&nbsp;

## Description
Specifies that a type can be converted to at least one of several other types.

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
#include <iostream>
#include <string>
#include <xieite/concepts/convertible_to_any.hpp>

template<xieite::concepts::ConvertibleToAny<bool, char, int>>
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
