# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:All\<\>
Defined in header [<xieite/concepts/all.hpp>](../../../include/xieite/concepts/all.hpp)

&nbsp;

## Description
Specifies that a type satisfies all of several type traits. Expects trait-like structure templates. Passing no trait templates evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept All = (... && Traits<Type>::value);
```

&nbsp;

## Example
```cpp
#include <print>
#include <type_traits>
#include "xieite/concepts/all.hpp"

template<xieite::concepts::All<std::is_integral, std::is_signed> T>
void test(T value) {
    std::println("yes: {}", value);
}

template<typename T>
void test(T&& value) {
    std::println("no: {}", value);
}

int main() {
    test(17);
    test(999ULL);
}
```
Output:
```
yes: 17
no: 999
```
