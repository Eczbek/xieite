# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:CopyMoveConstructible\<\>
Defined in fragment [xieite:containers.CopyMoveConstructible](../../../src/containers/maybe_move_constructible.cpp)

&nbsp;

## Description
Implicitly matches the presence of a move constructor in `Type` for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using CopyMoveConstructible = xieite::containers::MaybeMoveConstructible<std::is_move_constructible_v<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeMoveConstructible<false> {};

struct Bar
: xieite::containers::CopyMoveConstructible<Foo> {};

int main() {
    std::println("{}", std::is_move_constructible_v<Foo>);
    std::println("{}", std::is_move_constructible_v<Bar>);
}
```
Output:
```
false
false
```
