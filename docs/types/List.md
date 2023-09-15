# [xieite](../xieite.md)\:\:[types](../types.md)\:\:List
Defined in header [<xieite/types/List.hpp>](../../include/xieite/types/List.hpp)

&nbsp;

## Description
A structure for operating on a list of types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Types>
struct List {
    using Data = std::tuple<Types...>;

    template<typename... OtherTypes>
    using Append = xieite::types::List<Types..., OtherTypes...>;

    template<typename... OtherTypes>
    using Prepend = xieite::types::List<OtherTypes..., Types...>;

    using Unique = /* ... */;

    template<std::size_t start, std::size_t end = sizeof...(Types)>
    using Slice = /* ... */;

    using Reverse = /* ... */;
};
```
##### Member types
- [Data](./List/1/Data.md)
- [Append](./List/1/Append.md)
- [Prepend](./List/1/Prepend.md)
- [Unique](./List/1/Unique.md)
- [Slice](./List/1/Slice.md)
- [Reverse](./List/1/Reverse.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using Foo = xieite::types::List<int, char, int, int, char>;
    using Bar = Foo::Append<float, double, float, float, double>;
    using Baz = Bar::Prepend<short, long, short, short, long>;
    using Qux = Baz::Unique;
    using Corge = Qux::Slice<1, 5>;
    using Grault = Corge::Reverse;
    using Garply = Corge::Data;

    std::cout
        << xieite::types::demangle(typeid(Foo).name()) << '\n'
        << xieite::types::demangle(typeid(Bar).name()) << '\n'
        << xieite::types::demangle(typeid(Baz).name()) << '\n'
        << xieite::types::demangle(typeid(Qux).name()) << '\n'
        << xieite::types::demangle(typeid(Corge).name()) << '\n'
        << xieite::types::demangle(typeid(Grault).name()) << '\n'
        << xieite::types::demangle(typeid(Garply).name()) << '\n';
}
```
Output:
```
xieite::types::List<int, char, int, int, char>
xieite::types::List<int, char, int, int, char, float, double, float, float, double>
xieite::types::List<short, long, short, short, long, int, char, int, int, char, float, double, float, float, double>
xieite::types::List<short, long, int, char, float, double>
xieite::types::List<long, int, char, float>
xieite::types::List<float, char, int, long>
std::tuple<long, int, char, float>
```
