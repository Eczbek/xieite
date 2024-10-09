# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:also\<\>\(\)
Defined in fragment [xieite:functors.also](../../../src/functors/also.cpp)

&nbsp;

## Description
Returns a copy of a value before passing it to a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::CopyConstructible Type, std::invocable<Type&&> Functor>
[[nodiscard]] constexpr Type also(Type&& value, Functor&& functor)
noexcept(std::is_nothrow_copy_constructible_v<Type> && std::is_nothrow_invocable_v<Functor, Type&&>);
```
#### 2)
```cpp
template<xieite::concepts::CopyConstructible Type, std::invocable<> Functor>
[[nodiscard]] constexpr Type also(Type&& value, Functor&& functor)
XIEITE_ARROW_BASE(xieite::functors::also(/* ... */))
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    int x = 5;

    auto increment = [](int& y) {
        y += 5;
    };

    std::println("{}", xieite::functors::also(x, increment));
    std::println("{}", x);
}
```
Possible output:
```
5
10
```
