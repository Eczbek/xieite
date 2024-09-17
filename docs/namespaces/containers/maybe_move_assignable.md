# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:MaybeMoveAssignable\<\> \{\}
Defined in fragment [xieite:containers.MaybeMoveAssignable](../../../src/containers/maybe_move_assignable.cpp)

&nbsp;

## Description
Implicitly deletes the move assignment member function for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<bool>
struct MaybeMoveAssignable {};
```
#### 2)
```cpp
template<>
struct MaybeMoveAssignable<false> {
    MaybeMoveAssignable() = default;
    MaybeMoveAssignable(const xieite::containers::MaybeMoveAssignable<false>&) = default;
    MaybeMoveAssignable(xieite::containers::MaybeMoveAssignable<false>&&) = default;
    xieite::containers::MaybeMoveAssignable<false>& operator=(const xieite::containers::MaybeMoveAssignable<false>&) = default;
    auto operator=(xieite::containers::MaybeMoveAssignable<false>&&) = delete;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeMoveAssignable<true> {};

struct Bar
: xieite::containers::MaybeMoveAssignable<false> {};

int main() {
    std::println("{}", std::is_move_assignable_v<Foo>);
    std::println("{}", std::is_move_assignable_v<Bar>);
}
```
Output:
```
true
false
```
