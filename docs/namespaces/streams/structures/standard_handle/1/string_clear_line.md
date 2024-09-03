# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringClearLine\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which, when printed, clears the line which contains the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringClearLine() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string clear = xieite::streams::StandardHandle::stringClearLine();

    std::string message = "Hello, " + clear + "world!";

    std::println("{}", message);
}
```
Possible output:
```
       world!
```
