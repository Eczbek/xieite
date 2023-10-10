# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAny
Defined in header [<xieite/concepts/same_as_any.hpp>](../../../include/xieite/concepts/same_as_any.hpp)

&nbsp;

## Description
Specifies that a type is the same as at least one of several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAny = (... || std::same_as<Source, Targets>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/same_as_any.hpp>

template<xieite::concepts::SameAsAny<bool, char, int>>
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
