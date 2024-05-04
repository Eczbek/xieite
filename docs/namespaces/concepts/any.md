# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Any\<\>
Defined in header [<xieite/concepts/any.hpp>](../../../include/xieite/concepts/any.hpp)

&nbsp;

## Description
Specifies that a type satisfies at least one of several type traits. Expects trait-like structure templates. Passing no trait templates evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename> typename... Traits_>
concept Any = (... || Traits_<Type_>::value);
```

&nbsp;

## Example
```cpp
#include <print>
#include <type_traits>
#include "xieite/concepts/any.hpp"

template<xieite::concepts::Any<std::is_integral, std::is_floating_point> T>
void test(T value) {
    std::println("yes: {}", value);
}

template<typename T>
void test(T&& value) {
    std::println("no: {}", value);
}

int main() {
    test(3.14159);
    test("\"something\"");
}
```
Output:
```
yes: 3.14159
no: "something"
```
