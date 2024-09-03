# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorAlternate\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables the alternate cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
void setCursorAlternate(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setCursorAlternate(true);
    std::print("Hello there");
    terminal.setCursorAlternate(false);
    std::println("world!");
}
```
Possible output:
```
world!there
```
