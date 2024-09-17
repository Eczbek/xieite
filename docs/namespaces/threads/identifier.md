# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:identifier
Defined in fragment [xieite:threads.identifier](../../../src/threads/identifier.cpp)

&nbsp;

## Description
Gives an identifier to each unique thread.

&nbsp;

## Synopsis
#### 1)
```cpp
thread_local const std::size_t identifier = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto x = std::jthread([] {
        std::println("{}", xieite::threads::identifier);
    });

    auto y = std::jthread([] {
        std::println("{}", xieite::threads::identifier);
    });

    auto z = std::jthread([] {
        std::println("{}", xieite::threads::identifier);
    });
}
```
Possible output:
```
0
1
2
```
