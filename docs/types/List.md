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
    static constexpr std::size_t size = sizeof...(Types);

    using Data = std::tuple<Types...>;

    template<std::size_t index>
    using At = std::conditional_t<index < sizeof...(Types), std::tuple_element<index, List<Types...>::Data>, std::type_identity<void>>::type;

    using First = List<Types...>::At<0>;

    using Last = List<Types...>::At<sizeof...(Types) - 1>;

    template<typename... OtherTypes>
    using Append = List<Types..., OtherTypes...>;

    template<typename... OtherTypes>
    using Prepend = List<OtherTypes..., Types...>;

    template<std::size_t, std::size_t = sizeof...(Types)>
    using Slice = /* ... */;

    using Reverse = /* ... */;

    template<typename>
    using AppendRange = /* ... */;

    template<typename>
    using PrependRange = /* ... */;

    template<std::size_t start, std::size_t end = start + 1>
    using Erase = List<Types...>::Slice<0, start>::template AppendRange<List<Types...>::Slice<end>>;

    template<std::size_t index, typename... OtherTypes>
    using Insert = List<Types...>::Slice<0, index>::template Append<OtherTypes...>::template AppendRange<List<Types...>::Slice<index>>;

    template<std::size_t index, typename OtherType>
    using Set = List<Types...>::Erase<index>::template Insert<index, OtherType>;

    template<std::size_t index1, std::size_t index2>
    using Swap = List<Types...>::template Set<index1, List<Types...>::At<index2>>::template Set<index2, List<Types...>::At<index1>>;

    template<std::size_t, typename>
    using InsertRange = /* ... */;

    template<std::size_t start, std::size_t end, typename... OtherTypes>
    using Replace = List<Types...>::Erase<start, end>::template Insert<start, OtherTypes...>;

    template<std::size_t, std::size_t, typename>
    using ReplaceRange = /* ... */;

    template<std::size_t, std::size_t, std::size_t, std::size_t>
    using SwapRanges = /* ... */;

    using Unique = /* ... */;
};
```
##### Member types
- [Data](./List/1/Data.md)
- [At](./List/1/At.md)
- [First](./List/1/First.md)
- [Last](./List/1/Last.md)
- [Reverse](./List/1/Reverse.md)
- [Append](./List/1/Append.md)
- [AppendRange](./List/1/AppendRange.md)
- [Prepend](./List/1/Prepend.md)
- [PrependRange](./List/1/PrependRange.md)
- [Slice](./List/1/Slice.md)
- [Erase](./List/1/Erase.md)
- [Insert](./List/1/Insert.md)
- [InsertRange](./List/1/InsertRange.md)
- [Set](./List/1/Set.md)
- [Replace](./List/1/Replace.md)
- [ReplaceRange](./List/1/ReplaceRange.md)
- [Swap](./List/1/Swap.md)
- [SwapRanges](./List/1/SwapRanges.md)
- [Unique](./List/1/Unique.md)
##### Member values
- [size](./List/1/size.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using Foo = xieite::types::List<int, char, short, long>;
    using Bar = Foo::Append<float, double>;
    using Baz = Bar::Reverse;
    using Qux = Baz::Erase<3>;

    std::cout << xieite::types::demangle(typeid(Qux::Data).name()) << '\n';
}
```
Output:
```
std::tuple<double, float, long, char, int>
```
