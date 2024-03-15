# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:durations
Defined in header [<xieite/literals/durations.hpp>](../../../include/xieite/literals/durations.hpp)

&nbsp;

## Description
A namespace of literals for constructing various durations.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::chrono::nanoseconds operator""_nanoseconds(unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::chrono::microseconds operator""_microseconds(unsigned long long int value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr std::chrono::milliseconds operator""_milliseconds(unsigned long long int value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr std::chrono::seconds operator""_seconds(unsigned long long int value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr std::chrono::minutes operator""_minutes(unsigned long long int value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr std::chrono::hours operator""_hours(unsigned long long int value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr std::chrono::days operator""_days(unsigned long long int value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr std::chrono::weeks operator""_weeks(unsigned long long int value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr std::chrono::months operator""_months(unsigned long long int value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr std::chrono::years operator""_years(unsigned long long int value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr xieite::time::Decades operator""_decades(unsigned long long int value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr xieite::time::Centuries operator""_centuries(unsigned long long int value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr xieite::time::Millenniums operator""_millenniums(unsigned long long int value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr xieite::time::Epochs operator""_epochs(unsigned long long int value) noexcept;
```
#### 15)
```cpp
[[nodiscard]] constexpr xieite::time::Eons operator""_eons(unsigned long long int value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <thread>
#include "xieite/literals/durations.hpp"

int main() {
    using namespace xieite::literals::durations;

    std::this_thread::sleep_for(2_eons);

    std::println("done");
}
```
Theoretical output:
```
done
```
