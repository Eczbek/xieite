# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Pipe](../../../pipe.md)\:\:descriptor\(\)
Defined in fragment [xieite:streams.Pipe](../../../../../../src/streams/pipe.cpp)

&nbsp;

## Description
Returns the underlying file descriptor.

&nbsp;

## Synopsis
#### 1)
```cpp
import std;
import xieite;
[[nodiscard]] int descriptor() const noexcept;
#endif
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto pipe = xieite::streams::Pipe("echo Hello, world!", "r");

    std::println("{}", pipe.descriptor());
}
```
Possible output:
```
3
```
