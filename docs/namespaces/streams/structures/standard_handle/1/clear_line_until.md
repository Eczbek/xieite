# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearLineUntil\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Clears from the beginning of a line until the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearLineUntil() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello,\nworld!");

    terminal.clearLineUntil();
}
```
Possible output:
```
Hello,
      
```
