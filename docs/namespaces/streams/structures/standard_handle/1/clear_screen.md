# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearScreen\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Clears the entire screen.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearScreen() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello, ");

    terminal.clearScreen();

    std::println("world!");
}
```
Possible output:
```
       world!
```
