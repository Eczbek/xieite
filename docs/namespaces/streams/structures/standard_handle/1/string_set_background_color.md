# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetBackgroundColor\<\>\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which sets the background color when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t channels>
requires(channels >= 3)
[[nodiscard]] static constexpr std::string stringSetBackgroundColor(const xieite::graphics::Color<channels>& color) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string color = xieite::streams::StandardHandle::stringSetBackgroundColor(xieite::streams::Color<3>(255, 0, 0));

    std::string message = color + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:

![image](./set_background_color.png)
