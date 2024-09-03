# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:time\<\>\(\)
Defined in fragment [xieite:functors.time](../../../src/functors/time.cpp)

&nbsp;

## Description
Times the duration of execution of a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Duration = std::chrono::nanoseconds, xieite::concepts::Clock Clock = std::chrono::steady_clock, typename... Arguments, std::invocable<Arguments...> Functor>
[[nodiscard]] Duration time(Functor&& functor, Arguments&&... arguments)
noexcept(std::is_nothrow_invocable_v<Functor, Arguments...>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{} nanoseconds", xieite::functors::time([] {
        volatile int i = 0;
        while (i < 10'000) {
            i = i + 1;
        }
    }).count());
}
```
Possible output:
```
24710 nanoseconds
```
