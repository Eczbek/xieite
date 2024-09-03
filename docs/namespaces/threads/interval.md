# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Interval \{\}
Defined in fragment [xieite:threads.Interval](../../../src/threads/interval.cpp)

&nbsp;

## Description
Runs a callback every set amount of time.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Interval {
    template<std::invocable<> Functor, xieite::concepts::Duration Duration>
    Interval(Functor&&, Duration) noexcept;

    explicit operator bool() const noexcept;

    void stop() noexcept;
};
```
- [Interval\<\>\(\)](./structures/interval/1/operators/constructor.md)
- [operator typename\(\)](./structures/interval/1/operators/cast.md)
- [stop\(\)](./structures/interval/1/stop.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto interval = xieite::threads::Interval([] {
        static int i = 0;

        std::println("{}", ++i);
    }, std::chrono::seconds(1));

    std::this_thread::sleep_for(std::chrono::seconds(5));
}
```
Possible output:
```
1
2
3
4
```
