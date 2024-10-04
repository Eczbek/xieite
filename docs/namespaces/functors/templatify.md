# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:templatify\<\>\(\)
Defined in fragment [xieite:functors.templatify](../../../src/functors/templatify.cpp)

&nbsp;

## Description
Performs a slight bit of spacetime manipulation. `Functor` must be default-constructible.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr void templatify(auto functor, const std::uint8_t value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto functor = []<std::uint8_t x> { std::println("{}", x); };

    xieite::functors::templatify(functor, 14);
}
```
Output:
```
14
```
