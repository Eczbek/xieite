# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:count
Defined in header [<xieite/algorithms/count.hpp>](../../include/xieite/algorithms/count.hpp)

&nbsp;

## Description
Counts and returns the number of arguments passed.

&nbsp;

## Synopsis
```cpp
template<typename... Values>
[[nodiscard]]
constexpr std::size_t count(const Values&... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/count.hpp>

int main() {
    std::cout << xieite::algorithms::count(1, 0.4, 'e', "aaa") << '\n';
}
```
Output:
```
4
```
