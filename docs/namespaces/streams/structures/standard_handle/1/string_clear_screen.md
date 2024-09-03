# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringClearScreen\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which clears the entire screen when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringClearScreen() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string clear = xieite::streams::StandardHandle::stringClearScreen();

    std::string message = "Hello, " + clear + "world!";

    std::println("{}", message);
}
```
Possible output:
```
       world!
```
