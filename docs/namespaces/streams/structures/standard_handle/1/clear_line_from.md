# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearLineFrom\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Clears from the cursor until the end of a line.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearLineFrom() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello,\nworld!\r");

    terminal.clearLineFrom();
}
```
Possible output:
```
Hello,
      
```
