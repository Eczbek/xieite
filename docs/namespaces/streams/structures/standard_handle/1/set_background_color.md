# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setBackgroundColor\<\>\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Sets the background color.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t channels>
requires(channels >= 3)
void setBackgroundColor(const xieite::graphics::Color<channels>& color) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setBackgroundColor(xieite::streams::Color<3>(0, 0, 255));
    std::println("Hello, world!");
}
```
Possible output:

![image](./set_background_color.png)
