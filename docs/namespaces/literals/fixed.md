# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:fixed
Defined in fragment [xieite:literals.fixed](../../../src/literals/fixed.cpp)

&nbsp;

## Description
A namespace for a literal that constructs a `xieite::containers::FixedString`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::containers::FixedString>
[[nodiscard]] constexpr auto operator""_fixed() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

template<xieite::containers::FixedString string>
void f() {
    std::println("{}", string.view());
}

int main() {
    using namespace xieite::literals::fixed;

    f<"hello"_fixed>();
}
```
Output:
```
hello
```
