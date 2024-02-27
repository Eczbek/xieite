# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToAll
Defined in header [<xieite/concepts/no_throw_convertible_to_all.hpp>](../../../include/xieite/concepts/no_throw_convertible_to_all.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types without throwing exceptions. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAll = (... && xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
```

&nbsp;

## Example
```cpp
#include <print>
#include <stdexcept>
#include "xieite/concepts/no_throw_convertible_to_all.hpp"

struct Nope {
    operator int() {
        return 4;
    }

    operator double() {
        throw std::runtime_error("nope");
    }
};

template<xieite::concepts::NoThrowConvertibleToAll<int, double>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<bool>();
    test<Nope>();
}
```
Output:
```
yep
nope
```
