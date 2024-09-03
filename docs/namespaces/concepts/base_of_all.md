# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:BaseOfAll\<\>
Defined in fragment [xieite:concepts.BaseOfAll](../../../src/concepts/base_of_all.cpp)

&nbsp;

## Description
Specifies that a type is a base of all of several other derived types. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Base, typename... Derived>
concept BaseOfAll = (... && xieite::concepts::BaseOf<Base, Derived>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo {};

struct Bar {};

struct Baz
: Foo {};

struct Qux
: Foo, Bar {};

int main() {
    std::println("{}", xieite::concepts::BaseOfAll<Foo, Baz, Qux>);
    std::println("{}", xieite::concepts::BaseOfAll<Bar, Baz, Qux>);
}
```
Output:
```
true
false
```
