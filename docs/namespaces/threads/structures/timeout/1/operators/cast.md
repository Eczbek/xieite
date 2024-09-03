# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Timeout](../../../../timeout.md)\:\:operator typename\(\)
Defined in fragment [xieite:threads.Timeout](../../../../../../../src/threads/timeout.cpp)

&nbsp;

## Description
The boolean cast eturns `true` if the timeout is still waiting, and `false` if it has been stopped.

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
    auto timeout = xieite::threads::Timeout([] {
        std::println("xyz");
    }, std::chrono::seconds(5));

    std::println("{}", static_cast<bool>(timeout));

    timeout.stop();

    std::println("{}", static_cast<bool>(timeout));
}
```
Output:
```
true
false
```
