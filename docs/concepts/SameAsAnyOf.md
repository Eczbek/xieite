# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:SameAsAnyOf
Defined in header [<xieite/concepts/SameAsAnyOf.hpp>](../../include/xieite/concepts/SameAsAnyOf.hpp)

&nbsp;

## Description
Specifies that a type is the same as at least one of several other types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAnyOf = (std::same_as<Source, Targets> || ...);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/SameAsAnyOf.hpp>

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
