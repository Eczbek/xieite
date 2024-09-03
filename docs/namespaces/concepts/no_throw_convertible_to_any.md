# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToAny\<\>
Defined in fragment [xieite:concepts.NoThrowConvertibleToAny](../../../src/concepts/no_throw_convertible_to_any.cpp)

&nbsp;

## Description
Specifies that a type can be converted to at least one of several other types without throwing exceptions. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAny = (... || xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {
    operator int() {
        return 4;
    }

    operator double() {
        throw std::runtime_error("nope");
    }
};

template<xieite::concepts::NoThrowConvertibleToAny<int, double>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<bool>();
    test<Nope>();
}
```
Output:
```
yep
yep
```
