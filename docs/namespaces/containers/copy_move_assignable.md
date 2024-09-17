# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:CopyMoveAssignable\<\>
Defined in fragment [xieite:containers.CopyMoveAssignable](../../../src/containers/maybe_move_assignable.cpp)

&nbsp;

## Description
Implicitly matches the presence of a copy assignment member function in `Type` for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using CopyMoveAssignable = xieite::containers::MaybeMoveAssignable<std::is_move_assignable_v<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeMoveAssignable<false> {};

struct Bar
: xieite::containers::CopyMoveAssignable<Foo> {};

int main() {
    std::println("{}", std::is_move_assignable_v<Foo>);
    std::println("{}", std::is_move_assignable_v<Bar>);
}
```
Output:
```
false
false
```
