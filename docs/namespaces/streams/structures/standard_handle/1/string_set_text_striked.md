# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetTextStriked\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which enables or disables ~~strikethrough~~ text when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringSetTextStriked(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string striked = xieite::streams::StandardHandle::stringSetTextStriked(true);

    std::string message = striked + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:

![image](./set_text_striked.png)
