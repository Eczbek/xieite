# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setTextInvisible\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables text visibility.

&nbsp;

## Synopsis
#### 1)
```cpp
void setTextInvisible(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello, ");

    terminal.setTextInvisible(true);

    std::println("world!");
}
```
Possible output:
```
Hello,       
```
