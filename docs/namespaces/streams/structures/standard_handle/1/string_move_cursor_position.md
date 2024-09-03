# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringMoveCursorPosition\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which moves the terminal cursor's position when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringMoveCursorPosition(xieite::streams::Position difference) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string offset = xieite::streams::StandardHandle::stringMoveCursorPosition(xieite::streams::Position(2, 3));

    std::string message = offset + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:
```


  Hello, world!
```
