# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:List
Defined in header [<xieite/types/List.hpp>](../../../include/xieite/types/List.hpp)

&nbsp;

## Description
A structure for operating on a list of types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Types>
class List {
    static constexpr std::size_t size = sizeof...(Types);

    template<std::size_t index>
    using At = /* ... */;

    template<typename... OtherTypes>
    using Append = xieite::types::List<Types..., OtherTypes...>;

    template<typename... OtherTypes>
    using Prepend = xieite::types::List<OtherTypes..., Types...>;

    template<std::size_t start, std::size_t end = sizeof...(Types)>
    using Slice = /* ... */;

    using Reverse = /* ... */;

    template<typename Range>
    using AppendRange = /* ... */;

    template<typename Range>
    using PrependRange = /* ... */;

    template<std::size_t start, std::size_t end = start + 1>
    using Erase = xieite::types::List<Types...>::Slice<0, start>::template AppendRange<xieite::types::List<Types...>::Slice<end>>;

    template<std::size_t index, typename... OtherTypes>
    using Insert = xieite::types::List<Types...>::Slice<0, index>::template Append<OtherTypes...>::template AppendRange<xieite::types::List<Types...>::Slice<index>>;

    template<std::size_t index, typename OtherType>
    using Set = xieite::types::List<Types...>::Erase<index>::template Insert<index, OtherType>;

    template<std::size_t index1, std::size_t index2>
    using Swap = xieite::types::List<Types...>::template Set<index1, xieite::types::List<Types...>::At<index2>>::template Set<index2, xieite::types::List<Types...>::At<index1>>;

    template<std::size_t index, typename Range>
    using InsertRange = /* ... */;

    template<std::size_t start, std::size_t end, typename... OtherTypes>
    using Replace = xieite::types::List<Types...>::Erase<start, end>::template Insert<start, OtherTypes...>;

    template<std::size_t start, std::size_t end, typename Range>
    using ReplaceRange = /* ... */;

    template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
    using SwapRanges = xieite::types::List<Types...>::ReplaceRange<start1, end1, xieite::types::List<Types...>::Slice<start2, end2>>::template ReplaceRange<start2, end2, xieite::types::List<Types...>::Slice<start1, end1>>;

    template<std::size_t count>
    using Repeat = /* ... */;

    using Unique = /* ... */;
    };
```
##### Member types
- [Append](./structures/List/1/Append.md)
- [AppendRange](./structures/List/1/AppendRange.md)
- [At](./structures/List/1/At.md)
- [Erase](./structures/List/1/Erase.md)
- [Insert](./structures/List/1/Insert.md)
- [InsertRange](./structures/List/1/InsertRange.md)
- [Prepend](./structures/List/1/Prepend.md)
- [PrependRange](./structures/List/1/PrependRange.md)
- [Replace](./structures/List/1/Replace.md)
- [ReplaceRange](./structures/List/1/ReplaceRange.md)
- [Reverse](./structures/List/1/Reverse.md)
- [Set](./structures/List/1/Set.md)
- [Slice](./structures/List/1/Slice.md)
- [Swap](./structures/List/1/Swap.md)
- [SwapRanges](./structures/List/1/SwapRanges.md)
- [Unique](./structures/List/1/Unique.md)
##### Member values
- [size](./structures/List/1/size.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using Foo = xieite::types::List<int, char, short, long>;
    using Bar = Foo::Append<float, double>;
    using Baz = Bar::Reverse;
    using Qux = Baz::Erase<3>;

    std::cout << xieite::types::name<Qux>() << '\n';
}
```
Output:
```
List<double, float, long, char, int>
```