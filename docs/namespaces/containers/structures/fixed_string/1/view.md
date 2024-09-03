# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedString<characters, Character>](../../../../fixed_string.md)\:\:view\(\)
Defined in fragment [xieite:containers.FixedString](../../../../../../../src/containers/fixed_string.cpp)

&nbsp;

## Description
Returns a view to the string's data.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view view() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::containers::FixedString string = "Hello, world!";

    std::println("{}", string.view());
}
```
Output:
```
Hello, world!
```
