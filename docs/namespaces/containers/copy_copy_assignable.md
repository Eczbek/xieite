# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:CopyCopyAssignable\<\>
Defined in fragment [xieite:containers.CopyCopyAssignable](../../../src/containers/maybe_copy_assignable.cpp)

&nbsp;

## Description
Implicitly matches the presence of a copy assignment member function in `Type` for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using CopyCopyAssignable = xieite::containers::MaybeCopyAssignable<std::is_copy_assignable_v<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeCopyAssignable<false> {};

struct Bar
: xieite::containers::CopyCopyAssignable<Foo> {};

int main() {
    std::println("{}", std::is_copy_assignable_v<Foo>);
    std::println("{}", std::is_copy_assignable_v<Bar>);
}
```
Output:
```
false
false
```
