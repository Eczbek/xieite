# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorShapeBlock\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Makes the cursor appear as a block.

&nbsp;

## Synopsis
#### 1)
```cpp
void setCursorShapeBlock(bool blink) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setCursorShapeBlock(false);

    std::fflush(stdout);
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
```
Possible output:

![image](./set_cursor_shape_block.png)
