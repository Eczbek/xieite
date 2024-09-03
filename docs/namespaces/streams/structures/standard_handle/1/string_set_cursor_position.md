# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetCursorPosition\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which sets the terminal cursor's position when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringSetCursorPosition(xieite::streams::Position position) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string position = xieite::streams::StandardHandle::stringSetCursorPosition(xieite::streams::Position(2, 5));

    std::string message = position + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:
```


     Hello, world!
```
