# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SpecializationOfAll
Defined in header [<xieite/concepts/specialization_of_all.hpp>](../../../include/xieite/concepts/specialization_of_all.hpp)

&nbsp;

## Description
Specifies that a type is a specialization of all of several templates.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename...> typename Template>
concept SpecializationOfAll = (... && xieite::concepts::SpecializationOf<Type, Templates>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/specialization_of_all.hpp"

template<typename>
struct Foo {};

template<typename>
struct Bar {};

int main() {
	using Baz = Foo<int>;

	std::println("{}", xieite::concepts::SpecializationOfAll<Baz, Foo, Foo>);
	std::println("{}", xieite::concepts::SpecializationOfAll<Baz, Foo, Bar>);
}
```
Output:
```
true
false
```
