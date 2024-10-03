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
requires(xieite::types::List<Arguments...>::Reverse::Prepend<Functor>::To<std::is_invocable>::value)
constexpr typename xieite::types::List<Arguments...>::Reverse::Prepend<Functor>::To<std::invoke_result>::type reverseArguments(Functor&& functor, Arguments&&... arguments)
noexcept(xieite::types::List<Arguments...>::Reverse::Prepend<Functor>::To<std::is_nothrow_invocable>::value);
```
#### 2)
```cpp
template<typename Structure, typename... Arguments>
requires(xieite::types::List<Arguments...>::Reverse::Prepend<Structure>::To<std::is_constructible>::value)
[[nodiscard]] constexpr Structure reverseArguments(Arguments&&... arguments)
noexcept(xieite::types::List<Arguments...>::Reverse::Prepend<Structure>::To<std::is_nothrow_constructible>::value);
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
