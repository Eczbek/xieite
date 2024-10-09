# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:reverseArguments\<\>\(\)
Defined in fragment [xieite:functors.reverseArguments](../../../src/functors/reverse_arguments.cpp)

&nbsp;

## Description
Passes arguments to a functor or a constructor in reversed order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, typename... Arguments>
constexpr auto reverseArguments(Functor&& functor, Arguments&&... arguments)
XIEITE_ARROW(/* ... */)
```
#### 2)
```cpp
template<typename Structure, typename... Arguments>
[[nodiscard]] constexpr Structure reverseArguments(Arguments&&... arguments)
XIEITE_ARROW_BASE(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

void foo(int x, char y, double z) {
    std::println("{} {} {}", x, y, z);
}

struct Bar {
    Bar(int x, char y, double z) {
        std::println("{} {} {}", x, y, z);
    }
};

int main() {
    xieite::functors::reverseArguments(foo, 3.14159, 'h', 17);

    Bar bar = xieite::functors::reverseArguments<Bar>(6.28318, 'E', 418);
}
```
Output:
```
17 h 3.14159
418 E 6.28318
```
