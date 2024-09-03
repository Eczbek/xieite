# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:List\<\> \{\}
Defined in fragment [xieite:types.List](../../../src/types/list.cpp)

&nbsp;

## Description
A structure for operating on a list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Types>
struct List {
    static constexpr std::size_t size = sizeof...(Types);

    template<typename Type, template<typename, typename> typename Comparator = std::is_same>
    static constexpr std::size_t count = /* ... */;

    template<typename Type, template<typename, typename> typename Comparator = std::is_same>
    static constexpr bool has = /* ... */;

    template<typename Type, template<typename, typename> typename Comparator = std::is_same>
    requires(xieite::types::List<Types...>::has<Type, Comparator>)
    static constexpr std::size_t find = /* ... */;

    template<std::size_t index>
    requires(index < sizeof...(Types))
    using At = /* xieite::types::List<...> */;

    template<template<typename...> typename Template>
    using Apply = /* xieite::types::List<...> */;

    template<typename... OtherTypes>
    using Append = /* xieite::types::List<...> */;

    template<typename... OtherTypes>
    using Prepend = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end = sizeof...(Types)>
    using Slice = /* xieite::types::List<...> */;

    using Reverse = /* xieite::types::List<...> */;

    template<typename Range>
    using AppendRange = /* xieite::types::List<...> */;

    template<typename Range>
    using PrependRange = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end = start + 1>
    using Erase = /* xieite::types::List<...> */;

    template<std::size_t index, typename... OtherTypes>
    using Insert = /* xieite::types::List<...> */;

    template<std::size_t index, typename OtherType>
    using Set = /* xieite::types::List<...> */;

    template<std::size_t index1, std::size_t index2>
    using Swap = /* xieite::types::List<...> */;

    template<std::size_t index, typename Range>
    using InsertRange = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end, typename... OtherTypes>
    using Replace = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end, typename Range>
    using ReplaceRange = /* xieite::types::List<...> */;

    template<std::size_t start1_, std::size_t end1_, std::size_t start2_, std::size_t end2_>
    using SwapRanges = /* xieite::types::List<...> */;

    template<template<typename, typename...> typename Selector>
    using Filter = /* xieite::types::List<...> */;

    template<typename<typename, typename...> typename Comparator = xieite::traits::IsSameAsAny>
    using Unique = /* xieite::types::List<...> */;

    template<std::size_t... i>
    using Rearrange = /* xieite::types::List<...> */;

    template<template<typename...> typename Transformer, std::size_t arity>
    requires((sizeof...(Types) % arity) == 0)
    using Transform = /* xieite::types::List<...> */;

    template<std::size_t count>
    using Repeat = /* xieite::types::List<...> */;

    template<typename... OtherTypes>
    using Zip = /* xieite::types::List<...> */;

    template<typename Range>
    using ZipRange = /* xieite::types::List<...> */;
};
```
- [Append\<\>](./structures/list/1/append.md)
- [AppendRange\<\>](./structures/list/1/append_range_of.md)
- [At\<\>](./structures/list/1/at.md)
- [Erase\<\>](./structures/list/1/erase.md)
- [Insert\<\>](./structures/list/1/Insert.md)
- [InsertRange\<\>](./structures/list/1/insert_range_of.md)
- [Prepend\<\>](./structures/list/1/prepend.md)
- [PrependRange\<\>](./structures/list/1/prepend_range_of.md)
- [Rearrange\<\>](./structures/list/1/rearrange.md)
- [Replace\<\>](./structures/list/1/replace.md)
- [ReplaceRange\<\>](./structures/list/1/replace_range.md)
- [Reverse](./structures/list/1/reverse.md)
- [Set\<\>](./structures/list/1/set.md)
- [Slice\<\>](./structures/list/1/slice.md)
- [Swap\<\>](./structures/list/1/swap.md)
- [SwapRanges\<\>](./structures/list/1/swap_ranges.md)
- [Transform\<\>](./structures/list/1/transform.md)
- [Unique\<\>](./structures/list/1/unique.md)
- [Sort\<\>](./structures/list/1/sort.md)
- size
- count\<\>
- has\<\>
- find\<\>

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Foo = xieite::types::List<int, char, short, long>;
    using Bar = Foo::Append<float, double>;
    using Baz = Bar::Reverse;
    using Qux = Baz::Erase<3>;

    std::println("{}", xieite::types::name<Qux>);
}
```
Possible output:
```
xieite::types::List<double, float, long, char, int>
```
