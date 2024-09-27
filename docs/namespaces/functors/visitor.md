# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Visitor\<\> \{\}
Defined in fragment [xieite:functors.Visitor](../../../src/functors/visitor.cpp)

&nbsp;

## Description
Derives from multiple bases and uses their `operator()`s.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Bases>
struct Visitor
: Bases... {
    using Bases::operator()...;
};
```

### Deduction guide
```cpp
template<typename... Bases>
Visitor(Bases...) -> Visitor<Bases...>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto foo = [](int) {
        std::println("foo");
    };
    auto bar = [](double) {
        std::println("bar");
    };

    auto visitor = xieite::functors::Visitor(foo, bar);

    visitor(999);
    visitor(3.14159);
}
```
Output:
```
foo
bar
```
