# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Loop](../../../../loop.md)\:\:operator typename\(\)
Defined in fragment [xieite:threads.Loop](../../../../../../../src/threads/loop.cpp)

&nbsp;

## Description
The boolean cast returns `true` if the loop is still running, and `false` if it has been stopped.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] explicit operator bool() const noexcept;
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

    std::println("{}", static_cast<bool>(loop));
}
```
Possible output:
```
false
```
