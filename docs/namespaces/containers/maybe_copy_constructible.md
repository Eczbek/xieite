# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:MaybeCopyConstructible\<\> \{\}
Defined in fragment [xieite:containers.MaybeCopyConstructible](../../../src/containers/maybe_copy_constructible.cpp)

&nbsp;

## Description
Implicitly deletes the copy constructor for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<bool>
struct MaybeCopyConstructible {};
```
#### 2)
```cpp
template<>
struct MaybeCopyConstructible<false> {
    MaybeCopyConstructible() = default;
    MaybeCopyConstructible(const xieite::containers::MaybeCopyConstructible<false>&) = delete;
    MaybeCopyConstructible(xieite::containers::MaybeCopyConstructible<false>&&) = default;
    xieite::containers::MaybeCopyConstructible<false>& operator=(const xieite::containers::MaybeCopyConstructible<false>&) = default;
    xieite::containers::MaybeCopyConstructible<false>& operator=(xieite::containers::MaybeCopyConstructible<false>&&) = default;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeCopyConstructible<true> {};

struct Bar
: xieite::containers::MaybeCopyConstructible<false> {};

int main() {
    std::println("{}", std::is_copy_constructible_v<Foo>);
    std::println("{}", std::is_copy_constructible_v<Bar>);
}
```
Output:
```
true
false
```
