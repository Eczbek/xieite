# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:CopyDefaultConstructible\<\>
Defined in fragment [xieite:containers.CopyDefaultConstructible](../../../src/containers/maybe_default_constructible.cpp)

&nbsp;

## Description
Implicitly matches the presence of a default constructor in `Type` for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using CopyDefaultConstructible = xieite::containers::MaybeDefaultConstructible<std::is_default_constructible_v<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeDefaultConstructible<false> {};

struct Bar
: xieite::containers::CopyDefaultConstructible<Foo> {};

int main() {
    std::println("{}", std::is_default_constructible_v<Foo>);
    std::println("{}", std::is_default_constructible_v<Bar>);
}
```
Output:
```
false
false
```
