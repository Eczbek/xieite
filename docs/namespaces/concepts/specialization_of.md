# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SpecializationOf\<\>
Defined in header [<xieite/concepts/specialization_of.hpp>](../../../include/xieite/concepts/specialization_of.hpp)

&nbsp;

## Description
Specifies that a type is a specialization of a template. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename...> typename Template_>
concept SpecializationOf = xieite::traits::IsSpecializationOf<std::remove_cv_t<Type_>, Template_>::value;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/specialization_of.hpp"

template<typename>
struct Foo {};

template<typename>
struct Bar {};

int main() {
    using Baz = Foo<int>;

    std::println("{}", xieite::concepts::SpecializationOf<Baz, Foo>);
    std::println("{}", xieite::concepts::SpecializationOf<Baz, Bar>);
}
```
Output:
```
true
false
```
