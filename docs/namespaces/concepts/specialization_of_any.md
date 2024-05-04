# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SpecializationOfAny\<\>
Defined in header [<xieite/concepts/specialization_of_any.hpp>](../../../include/xieite/concepts/specialization_of_any.hpp)

&nbsp;

## Description
Specifies that a type is a specialization of any of several templates.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename...> typename... Templates_>
concept SpecializationOfAny = (... || xieite::concepts::SpecializationOf<Type_, Templates_>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/specialization_of_any.hpp"

template<typename>
struct Foo {};

template<typename>
struct Bar {};

template<typename>
struct Baz {};

int main() {
    using Qux = Foo<int>;

    std::println("{}", xieite::concepts::SpecializationOfAny<Qux, Foo, Bar>);
    std::println("{}", xieite::concepts::SpecializationOfAny<Qux, Bar, Baz>);
}
```
Output:
```
true
false
```
