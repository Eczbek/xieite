# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:tupleify\(\)
Defined in header [<xieite/containers/tupleify.hpp>](../../../include/xieite/containers/tupleify.hpp)

&nbsp;

## Description
Creates a `std::tuple` from a structured-bindable type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Structure_>
[[nodiscard]] constexpr std::tuple<> tupleify(Structure_&&) noexcept;
```
#### 2..257)
```cpp
template<typename... Values_, typename Structure_>
requires(sizeof...(Values_) == /* 1..256 */)
[[nodiscard]] constexpr std::tuple<Values_...> tupleify(Structure_&& structure);
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include "xieite/containers/tupleify.hpp"

struct Foo {
    double x;
    char y;
};

int main() {
    Foo foo = Foo(99.5, 'b');

    auto bar = xieite::containers::tupleify<double, char&>(foo);

    std::get<0>(bar) = 27.0125;
    std::get<1>(bar) = 'Q';

    std::println("{} {}", foo.x, foo.y);
}
```
Output:
```
99.5
Q
```
