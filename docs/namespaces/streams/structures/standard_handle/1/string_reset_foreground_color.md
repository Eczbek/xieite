# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringResetForegroundColor\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which resets the text color to default when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringResetForegroundColor() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string color = xieite::streams::StandardHandle::stringSetForegroundColor(xieite::streams::Color<3>(255, 0, 0));
    std::string reset = xieite::streams::StandardHandle::stringResetForegroundColor();

    std::string message = color + "Hello, " + reset + "world!";

    std::println("{}", message);
}
```
Possible output:

![image](./reset_foreground_color.png)
