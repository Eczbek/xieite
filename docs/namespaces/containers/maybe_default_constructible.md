# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:MaybeDefaultConstructible\<\> \{\}
Defined in fragment [xieite:containers.MaybeDefaultConstructible](../../../src/containers/maybe_default_constructible.cpp)

&nbsp;

## Description
Implicitly deletes the default constructor for derived types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<bool>
struct MaybeDefaultConstructible {};
```
#### 2)
```cpp
template<>
struct MaybeDefaultConstructible<false> {
    MaybeDefaultConstructible() = delete;
    MaybeDefaultConstructible(const xieite::containers::MaybeDefaultConstructible<false>&) = default;
    MaybeDefaultConstructible(xieite::containers::MaybeDefaultConstructible<false>&&) = default;
    xieite::containers::MaybeDefaultConstructible<false>& operator=(const xieite::containers::MaybeDefaultConstructible<false>&) = default;
    xieite::containers::MaybeDefaultConstructible<false>& operator=(xieite::containers::MaybeDefaultConstructible<false>&&) = default;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::containers::MaybeDefaultConstructible<true> {};

struct Bar
: xieite::containers::MaybeDefaultConstructible<false> {};

int main() {
    std::println("{}", std::is_default_constructible_v<Foo>);
    std::println("{}", std::is_default_constructible_v<Bar>);
}
```
Output:
```
true
false
```
