# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:durations
Defined in fragment [xieite:literals.durations](../../../src/literals/durations.cpp)

&nbsp;

## Description
A namespace of literals for constructing various durations.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr auto operator""_nanoseconds(unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr auto operator""_microseconds(unsigned long long int value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr auto operator""_milliseconds(unsigned long long int value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr auto operator""_seconds(unsigned long long int value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr auto operator""_minutes(unsigned long long int value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr auto operator""_hours(unsigned long long int value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr auto operator""_days(unsigned long long int value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr auto operator""_weeks(unsigned long long int value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr auto operator""_months(unsigned long long int value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr auto operator""_years(unsigned long long int value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr auto operator""_decades(unsigned long long int value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr auto operator""_centuries(unsigned long long int value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr auto operator""_millenniums(unsigned long long int value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr auto operator""_epochs(unsigned long long int value) noexcept;
```
#### 15)
```cpp
[[nodiscard]] constexpr auto operator""_eons(unsigned long long int value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
