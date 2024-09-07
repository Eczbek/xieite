# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:compilation
Defined in fragment [xieite:time.compilation](../../../src/time/compilation.cpp)

&nbsp;

## Description
A namespace containing the date and time of the compilation of this translation unit.

&nbsp;

## Synopsis
#### 1)
```cpp
static constexpr int year = /* ... */;
```
#### 2)
```cpp
static constexpr int month = /* ... */;
```
#### 3)
```cpp
static constexpr int day = /* ... */;
```
#### 4)
```cpp
static constexpr int hour = /* ... */;
```
#### 5)
```cpp
static constexpr int minute = /* ... */;
```
#### 6)
```cpp
static constexpr int second = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::time::compilation;

    std::println("{}-{}-{} {}:{}:{}", years, months, days, hours, minutes, seconds);
}
```
Possible output:
```
2024-8-14 15:28:43
```
