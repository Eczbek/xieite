# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Loop](../../../loop.md)\:\:stop\(\)
Defined in fragment [xieite:threads.Loop](../../../../../../src/threads/loop.cpp)

&nbsp;

## Description
Stops a `xieite::threads::Loop`, and further callback calls.

&nbsp;

## Synopsis
#### 1)
```cpp
void stop() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto loop = xieite::threads::Loop([] {
        std::println("xyz");
    });

    loop.stop();
}
```
Possible output:
```
```
