# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setTextUnderlined\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables text <u>underlining</u>.

&nbsp;

## Synopsis
#### 1)
```cpp
void setTextUnderlined(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setTextUnderlined(true);

    std::println("Hello, world!");
}
```
Possible output:

![image](./set_text_underlined.md)
