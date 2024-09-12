# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\: \(temperature\)
Defined in fragment [xieite:units.temperature](../../../src/units/temperature.cpp)

&nbsp;

## Description
A collection of type aliases for temperature units.

&nbsp;

## Synopsis
#### 1)
```cpp
using Kelvin = xieite::units::Unit<"temperature", /* ... */>;
```
#### 2)
```cpp
using Celsius = xieite::units::Unit<"temperature", /* ... */>;
```
#### 3)
```cpp
using Fahrenheit = xieite::units::Unit<"temperature", /* ... */>;
```
#### 4)
```cpp
using Rankine = xieite::units::Unit<"temperature", /* ... */>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto celsius = xieite::units::Celsius(20);
    auto fahrenheit = static_cast<xieite::units::Fahrenheit>(celsius);

    std::println("{} *C", celsius.value);
    std::println("{} *F", fahrenheit.value);
}
```
Possible output:
```
20 *C
68 *F
```
