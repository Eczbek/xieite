# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Timeout \{\}
Defined in fragment [xieite:threads.Timeout](../../../src/threads/timeout.cpp)

&nbsp;

## Description
Runs a callback once after a set amount of time.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Timeout {
    template<std::invocable<> Functor, xieite::concepts::Duration Duration>
    Timeout(Functor&&, Duration) noexcept;

    explicit operator bool() const noexcept;

    void stop() noexcept;
};
```
- [Timeout\(\)](./structures/timeout/1/operators/constructor.md)
- [operator typename\(\)](./structures/timeout/1/operators/cast.md)
- [stop\(\)](./structures/timeout/1/stop.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto timeout = xieite::threads::Timeout([] {
        std::println("Hello,");
    }, std::chrono::seconds(3));

    std::println("world!");
}
```
Output:
```
world!
Hello,
```
