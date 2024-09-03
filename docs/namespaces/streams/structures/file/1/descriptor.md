# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[File](../../../file.md)\:\:descriptor\(\)
Defined in fragment [xieite:streams.File](../../../../../../src/streams/file.cpp)

&nbsp;

## Description
Returns the underlying file descriptor.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] int descriptor() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto file = xieite::streams::File(stdin);

    std::println("{}", file.descriptor());
}
```
Possible output:
```
0
```
