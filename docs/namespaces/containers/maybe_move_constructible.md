# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:MaybeMoveConstructible\<\> \{\}
Defined in fragment [xieite:containers.MaybeMoveConstructible](../../../src/containers/maybe_move_constructible.cpp)

&nbsp;

## Description
Implicitly deletes the move constructor for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<bool>
struct MaybeMoveConstructible {};
```
#### 2)
```cpp
template<>
struct MaybeMoveConstructible<false> {
    MaybeMoveConstructible() = default;
    MaybeMoveConstructible(const xieite::containers::MaybeMoveConstructible<false>&) = default;
    MaybeMoveConstructible(xieite::containers::MaybeMoveConstructible<false>&&) = delete;
    xieite::containers::MaybeMoveConstructible<false>& operator=(const xieite::containers::MaybeMoveConstructible<false>&) = default;
    xieite::containers::MaybeMoveConstructible<false>& operator=(xieite::containers::MaybeMoveConstructible<false>&&) = default;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeMoveConstructible<true> {};

struct Bar
: xieite::containers::MaybeMoveConstructible<false> {};

int main() {
    std::println("{}", std::is_move_constructible_v<Foo>);
    std::println("{}", std::is_move_constructible_v<Bar>);
}
```
Output:
```
true
false
```
