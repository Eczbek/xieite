# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SpecializationOfAny\<\>
Defined in fragment [xieite:concepts.SpecializationOfAny](../../../src/concepts/specialization_of_any.cpp)

&nbsp;

## Description
Specifies that a type is a specialization of any of several templates.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename...> typename... Templates>
concept SpecializationOfAny = (... || xieite::concepts::SpecializationOf<Type, Templates>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
