# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Overloader\<\> \{\}
Defined in fragment [xieite:functors.Overloader](../../../src/functors/overloader.cpp)

&nbsp;

## Description
Extends multiple invocable types and overloads its `operator()` for each.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Derivable... Derivables>
struct Overloader
: Derivables... {
    using Derivables::operator()...;
};
```

### Deduction guide
```cpp
template<typename... Functors>
Overloader(Functors...) -> xieite::functors::Overloader<Functors...>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto foo = [](int) -> void {
        std::println("foo");
    };
    auto bar = [](double) -> void {
        std::println("bar");
    };

    auto overloader = xieite::functors::Overloader(foo, bar);

    overloader(999);
    overloader(3.14159);
}
```
Output:
```
foo
bar
```
