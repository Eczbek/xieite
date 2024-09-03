# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NotAll\<\>
Defined in fragment [xieite:concepts.NotAll](../../../src/concepts/not_all.cpp)

&nbsp;

## Description
Negates type traits. Expects trait-like template structures. Passing no trait templates evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept NotAll = (... && !Traits<Type>::value);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

template<xieite::concepts::NotAll<std::is_floating_point, std::is_unsigned>>
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
yep
```
