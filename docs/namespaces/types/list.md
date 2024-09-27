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

    template<auto selector>
    static constexpr bool all = /* xieite::types::List<...> */;

    template<auto selector>
    static constexpr bool any = /* xieite::types::List<...> */;

    template<typename Type, auto comparator = []<typename Type, std::same_as<Type>> {}>
    static constexpr bool has = /* xieite::types::List<...> */;

    template<auto selector>
    requires(xieite::types::List<Types...>::any<selector>)
    static constexpr std::size_t find = /* ... */;

    template<typename Type, auto comparator = []<typename Type, std::same_as<Type>> {}>
    requires(xieite::types::List<Types...>::has<Type, comparator>)
    static constexpr std::size_t get = /* ... */;

    template<std::size_t index>
    requires(index < sizeof...(Types))
    using At = /* ... */;

    static constexpr auto apply(auto) noexcept;

    template<template<typename...> typename Template>
    using ApplyRange = Template<Types...>;

    template<typename Type>
    using Signature = /* Type(Types...) */;

    template<typename... OtherTypes>
    using Append = /* xieite::types::List<...> */;

    template<typename Range>
    using AppendRange = /* xieite::types::List<...> */;

    template<typename... OtherTypes>
    using Prepend = /* xieite::types::List<...> */;

    template<typename Range>
    using PrependRange = /* xieite::types::List<...> */;

    using Reverse = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end = sizeof...(Types)>
    using Slice = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end = start + 1>
    using Erase = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end, typename... OtherTypes>
    using Replace = /* xieite::types::List<...> */;

    template<std::size_t start, std::size_t end, typename Range>
    using ReplaceRange = /* xieite::types::List<...> */;

    template<std::size_t index, typename... OtherTypes>
    using Insert = /* xieite::types::List<...> */;

    template<std::size_t index, typename Range>
    using InsertRange = /* xieite::types::List<...> */;

    template<std::size_t index, typename Type>
    using Set = /* xieite::types::List<...> */;

    template<std::size_t index1, std::size_t index2>
    using Swap = /* xieite::types::List<...> */;

    template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
    using SwapRanges = /* xieite::types::List<...> */;

    template<std::size_t... indices>
    using Arrange = /* xieite::types::List<...> */;

    template<auto selector>
    using Filter = /* xieite::types::List<...> */;

    template<auto comparator = []<typename Type, std::same_as<Type>> {}>
    using Deduplicate = /* xieite::types::List<...> */;

    template<std::size_t repetitions>
    using Repeat = /* xieite::types::List<...> */;

    template<std::size_t arity, auto transformer>
    requires(!(sizeof...(Types) % arity))
    using Transform = /* xieite::types::List<...> */;

    template<std::size_t arity, auto transformer>
    requires(!(sizeof...(Types) % arity))
    using TransformFlat = /* xieite::types::List<...> */;

    template<typename... OtherTypes>
    requires(sizeof...(Types) == sizeof...(OtherTypes))
    using Zip = /* xieite::types::List<...> */;

    template<typename Range>
    using ZipRange = /* xieite::types::List<...> */;
};
```
- [Append\<\>](./structures/list/1/append.md)
- [AppendRange\<\>](./structures/list/1/append_range_of.md)
- [ApplyRange\<\>](./structures/list/1/apply_range.md)
- [Arrange\<\>](./structures/list/1/arrange.md)
- [At\<\>](./structures/list/1/at.md)
- [Deduplicate\<\>](./structures/list/1/deduplicate.md)
- [Erase\<\>](./structures/list/1/erase.md)
- [Filter\<\>](./structures/list/1/filter.md)
- [Insert\<\>](./structures/list/1/Insert.md)
- [InsertRange\<\>](./structures/list/1/insert_range_of.md)
- [Prepend\<\>](./structures/list/1/prepend.md)
- [PrependRange\<\>](./structures/list/1/prepend_range_of.md)
- [Replace\<\>](./structures/list/1/replace.md)
- [ReplaceRange\<\>](./structures/list/1/replace_range.md)
- [Reverse](./structures/list/1/reverse.md)
- [Set\<\>](./structures/list/1/set.md)
- [Signature\<\>](./structures/list/1/signature.md)
- [Slice\<\>](./structures/list/1/slice.md)
- [Swap\<\>](./structures/list/1/swap.md)
- [SwapRanges\<\>](./structures/list/1/swap_ranges.md)
- [Transform\<\>](./structures/list/1/transform.md)
- [TransformFlat\<\>](./structures/list/1/transform_flat.md)
- [Zip\<\>](./structures/list/1/zip.md)
- [ZipRange\<\>](./structures/list/1/zip_range.md)
- [apply\<\>\(\)](./structures/list/1/apply.md)
- size
- [all\<\>](./structures/list/1/all.md)
- [any\<\>](./structures/list/1/any.md)
- [has\<\>](./structures/list/1/has.md)
- [find\<\>](./structures/list/1/find.md)
- [get\<\>](./structures/list/1/get.md)

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
