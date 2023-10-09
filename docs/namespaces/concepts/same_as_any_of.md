# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAnyOf
Defined in header [<xieite/concepts/same_as_any_of.hpp>](../../../include/xieite/concepts/same_as_any_of.hpp)

&nbsp;

## Description
Specifies that a type is the same as at least one of several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAnyOf = (... || std::same_as<Source, Targets>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/same_as_any_of.hpp>

template<xieite::concepts::SameAsAnyOf<bool, char, int>>
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
