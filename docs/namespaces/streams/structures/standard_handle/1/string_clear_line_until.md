# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringClearLineUntil\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which, when printed, clears from the beginning of a line until the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringClearLineUntil() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string clear = xieite::streams::StandardHandle::stringClearLineUntil();

    std::string message = "Hello, " + clear + "world!";

    std::println("{}", message);
}
```
Possible output:
```
       world!
```
