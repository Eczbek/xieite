# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:None\<\>
Defined in fragment [xieite:concepts.None](../../../src/concepts/none.cpp)

&nbsp;

## Description
Negates type traits. Expects trait-like template structures. Passing no trait templates evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept None = (... && !Traits<Type>::value);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

template<xieite::concepts::None<std::is_integral>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<double>();
    test<int>();
}
```
Output:
```
yep
nope
```
