# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:arity \{\}
Defined in fragment [xieite:types.arity](../../../src/types/arity.cpp)

&nbsp;

## Description
An enumeration of arity values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Aggregate Type>
constexpr std::size_t arity = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo {
    int a;
    int x[2];
    int c;
    int y[999];
    int d;
};

int main() {
    std::println("{}", xieite::types::arity<Foo>);
}
```
Output:
```
5
```
