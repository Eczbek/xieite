# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setScreenAlternate\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables the alternate screen.

&nbsp;

## Synopsis
#### 1)
```cpp
void setScreenAlternate(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setScreenAlternate(true);
    std::print("Hello, ");
    terminal.setScreenAlternate(false);
    std::println("world!");
}
```
Possible output:
```
world!
```
