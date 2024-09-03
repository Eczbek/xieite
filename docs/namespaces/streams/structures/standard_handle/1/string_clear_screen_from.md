# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringClearScreenFrom\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which, when printed, clears from the cursor until the end of the screen.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringClearScreenFrom() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string clear = xieite::streams::StandardHandle::stringClearScreenFrom();

    std::string message = "Hello,\nworld!\r" + clear;

    std::println("{}", message);
}
```
Possible output:
```
Hello,
      
```
