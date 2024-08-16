# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:compilation
Defined in header [<xieite/time/compilation.hpp>](../../../include/xieite/time/compilation.hpp)

&nbsp;

## Description
A namespace containing the date and time of the compilation of this translation unit.

&nbsp;

## Synopsis
#### 1)
```cpp
static constexpr int years = /* ... */;
```
#### 2)
```cpp
static constexpr int months = /* ... */;
```
#### 3)
```cpp
static constexpr int days = /* ... */;
```
#### 4)
```cpp
static constexpr int hours = /* ... */;
```
#### 5)
```cpp
static constexpr int minutes = /* ... */;
```
#### 6)
```cpp
static constexpr int seconds = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/time/compilation.hpp"

int main() {
    using namespace xieite::time::compilation;

    std::println("{}-{}-{} {}:{}:{}", years, months, days, hours, minutes, seconds);
}
```
Possible output:
```
2024-8-14 15:28:43
```
