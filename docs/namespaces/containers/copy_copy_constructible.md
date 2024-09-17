# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:CopyCopyConstructible\<\>
Defined in fragment [xieite:containers.CopyCopyConstructible](../../../src/containers/maybe_copy_constructible.cpp)

&nbsp;

## Description
Implicitly matches the presence of a copy constructor in `Type` for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using CopyCopyConstructible = xieite::containers::MaybeCopyConstructible<std::is_copy_constructible_v<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeCopyConstructible<false> {};

struct Bar
: xieite::containers::CopyCopyConstructible<Foo> {};

int main() {
    std::println("{}", std::is_copy_constructible_v<Foo>);
    std::println("{}", std::is_copy_constructible_v<Bar>);
}
```
Output:
```
false
false
```
