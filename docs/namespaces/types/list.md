# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:List
Defined in header [<xieite/types/list.hpp>](../../../include/xieite/types/list.hpp)

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
- [Append](./structures/list/1/append.md)
- [AppendRange](./structures/list/1/append_range.md)
- [At](./structures/list/1/at.md)
- [Erase](./structures/list/1/erase.md)
- [Insert](./structures/list/1/Insert.md)
- [InsertRange](./structures/list/1/insert_range.md)
- [Prepend](./structures/list/1/prepend.md)
- [PrependRange](./structures/list/1/prepend_range.md)
- [Replace](./structures/list/1/Replace.md)
- [ReplaceRange](./structures/list/1/ReplaceRange.md)
- [Reverse](./structures/list/1/reverse.md)
- [Set](./structures/list/1/set.md)
- [Slice](./structures/list/1/slice.md)
- [Swap](./structures/list/1/swap.md)
- [SwapRanges](./structures/list/1/swap_ranges.md)
- [Unique](./structures/list/1/unique.md)
##### Member values
- [size](./structures/list/1/size.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>
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
