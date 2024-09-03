# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setTextStriked\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables ~~strikethrough~~ text.

&nbsp;

## Synopsis
#### 1)
```cpp
void setTextStriked(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setTextStriked(true);

    std::println("Hello, world!");
}
```
Possible output:

![image](./set_text_striked.md)
