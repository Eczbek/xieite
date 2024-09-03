# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedString<characters, Character>](../../../../fixed_string.md)\:\:size\(\)
Defined in fragment [xieite:containers.FixedString](../../../../../../../src/containers/fixed_string.cpp)

&nbsp;

## Description
Returns the string size, not counting the null-terminator.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::size_t& size() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::containers::FixedString string = "Hello, world!";

    std::println("{}", string.size());
}
```
Output:
```
13
```
