# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setInputEcho\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables echoing. When echoing is disabled, pressed keys will not be visibly reflected in the terminal.

&nbsp;

## Synopsis
#### 1)
```cpp
void setInputEcho(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setInputEcho(false);

    std::println("{}", terminal.readCharacter());
}
```
Possible output:
```
h
```
