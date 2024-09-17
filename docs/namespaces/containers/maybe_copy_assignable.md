# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:MaybeCopyAssignable\<\> \{\}
Defined in fragment [xieite:containers.MaybeCopyAssignable](../../../src/containers/maybe_copy_assignable.cpp)

&nbsp;

## Description
Implicitly deletes the copy assignment member function for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<bool>
struct MaybeCopyAssignable {};
```
#### 2)
```cpp
template<>
struct MaybeCopyAssignable<false> {
    MaybeCopyAssignable() = default;
    MaybeCopyAssignable(const xieite::containers::MaybeCopyAssignable<false>&) = default;
    MaybeCopyAssignable(xieite::containers::MaybeCopyAssignable<false>&&) = default;
    auto operator=(const xieite::containers::MaybeCopyAssignable<false>&) = delete;
    xieite::containers::MaybeCopyAssignable<false>& operator=(xieite::containers::MaybeCopyAssignable<false>&&) = default;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeCopyAssignable<true> {};

struct Bar
: xieite::containers::MaybeCopyAssignable<false> {};

int main() {
    std::println("{}", std::is_copy_assignable_v<Foo>);
    std::println("{}", std::is_copy_assignable_v<Bar>);
}
```
Output:
```
true
false
```
