# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Pipe](../../../pipe.md)\:\:close\(\)
Defined in fragment [xieite:streams.Pipe](../../../../../../src/streams/pipe.cpp)

&nbsp;

## Description
Closes a pipe. Automatically called upon destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
int close() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto pipe = xieite::streams::Pipe("echo Hello, world!", "r");

    std::println("{}", pipe.close());
}
```
Possible output:
```
0
```
