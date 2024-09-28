# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:convertDurations\<\>\(\)
Defined in fragment [xieite:time.convertDurations](../../../src/time/convert_durations.cpp)

&nbsp;

## Description
Converts a duration into multiple other durations. Requires that every resulting duration is unique.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Source, xieite::concepts::Duration... Targets>
[[nodiscard]] constexpr std::tuple<Targets...> convertDurations(Source duration) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace std::chrono;
    using namespace std::literals;
    using namespace xieite::time;

    auto [h, m, s] = convertDurations<hours, minutes, seconds>(12345s);

    std::println("{}:{}:{}", h, m, s);
}
```
Output:
```
3:25:45
```
