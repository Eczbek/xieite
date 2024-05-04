# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:time\<\>\(\)
Defined in header [<xieite/functors/time.hpp>](../../../include/xieite/functors/time.hpp)

&nbsp;

## Description
Times the duration of execution of a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Duration_ = std::chrono::nanoseconds, xieite::concepts::Clock Clock_ = std::chrono::steady_clock, std::invocable<> Functor_>
Duration_ time(Functor_&& functor)
noexcept(xieite::concepts::NoThrowInvocable<Functor_>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/time.hpp"

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
