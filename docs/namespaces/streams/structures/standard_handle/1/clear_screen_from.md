# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearScreenFrom\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Clears from the cursor until the end of the screen.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearScreenFrom() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello,\nworld!\r");

    terminal.clearScreenFrom();
}
```
Possible output:
```
Hello,
      
```
