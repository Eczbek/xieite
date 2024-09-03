# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearScreenUntil\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Clears from the beginning of the screen until the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearScreenUntil() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello,");

    terminal.clearScreenUntil();

    std::print("world!");
}
```
Possible output:
```
      world!
```
