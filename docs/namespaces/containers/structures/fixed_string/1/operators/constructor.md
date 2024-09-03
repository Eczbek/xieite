# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedString<characters, Character>](../../../../fixed_string.md)\:\:FixedString\<\>\(\)
Defined in fragment [xieite:containers.FixedString](../../../../../../../src/containers/fixed_string.cpp)

&nbsp;

## Description
Constructs a `xieite::containers::FixedString`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t otherCharacters>
constexpr FixedString(const Character(&data)[otherCharacters]) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::containers::FixedString string = "Hello, world!";

    std::println("{}", string.data);
}
```
Output:
```
Hello, world!
```
