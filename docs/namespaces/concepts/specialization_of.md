# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SpecializationOf\<\>
Defined in fragment [xieite:concepts.SpecializationOf](../../../src/concepts/specialization_of.cpp)

&nbsp;

## Description
Specifies that a type is a specialization of a template. To be deprecated once universal template parameters are implemented.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename...> typename Template>
concept SpecializationOf = /* ... */;
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
