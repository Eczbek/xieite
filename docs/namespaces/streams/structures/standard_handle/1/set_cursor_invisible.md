# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorInvisible\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Shows or hides the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
void setCursorInvisible(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setCursorInvisible(true);

    std::print("Hello, world!");

    std::fflush(stdout);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::println();
}
```
Possible output:

![image](./set_cursor_invisible.png)
