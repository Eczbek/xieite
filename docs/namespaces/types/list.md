# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:List\<\> \{\}
Defined in header [<xieite/types/list.hpp>](../../../include/xieite/types/list.hpp)

&nbsp;

## Description
A structure for operating on a list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Types_>
struct List {
    static constexpr std::size_t size = sizeof...(Types_);

    template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
    static constexpr std::size_t count = /* ... */;

    template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
    static constexpr bool has = /* ... */;

    template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
    requires(xieite::types::List<Types_...>::has<Type_, Comparator_>)
    static constexpr std::size_t find = /* ... */;

    template<std::size_t index_>
    requires(index_ < sizeof...(Types_))
    using At = /* xieite::types::List<...> */;

    template<template<typename...> typename Template_>
    using Apply = /* xieite::types::List<...> */;

    template<typename... OtherTypes_>
    using Append = /* xieite::types::List<...> */;

    template<typename... OtherTypes_>
    using Prepend = /* xieite::types::List<...> */;

    template<std::size_t start_, std::size_t end_ = sizeof...(Types_)>
    using Slice = /* xieite::types::List<...> */;

    using Reverse = /* xieite::types::List<...> */;

    template<typename Range_>
    using AppendRange = /* xieite::types::List<...> */;

    template<typename Range_>
    using PrependRange = /* xieite::types::List<...> */;

    template<std::size_t start_, std::size_t end_ = start_ + 1>
    using Erase = /* xieite::types::List<...> */;

    template<std::size_t index_, typename... OtherTypes_>
    using Insert = /* xieite::types::List<...> */;

    template<std::size_t index_, typename OtherType_>
    using Set = /* xieite::types::List<...> */;

    template<std::size_t index1_, std::size_t index2_>
    using Swap = /* xieite::types::List<...> */;

    template<std::size_t index_, typename Range_>
    using InsertRange = /* xieite::types::List<...> */;

    template<std::size_t start_, std::size_t end_, typename... OtherTypes_>
    using Replace = /* xieite::types::List<...> */;

    template<std::size_t start_, std::size_t end_, typename Range_>
    using ReplaceRange = /* xieite::types::List<...> */;

    template<std::size_t start1_, std::size_t end1_, std::size_t start2_, std::size_t end2_>
    using SwapRanges = /* xieite::types::List<...> */;

    template<template<typename, typename...> typename Selector_>
    using Filter = /* xieite::types::List<...> */;

    template<typename<typename, typename...> typename Comparator_ = xieite::traits::IsSameAsAny>
    using Unique = /* xieite::types::List<...> */;

    template<std::size_t... i_>
    using Rearrange = /* xieite::types::List<...> */;

    template<template<typename...> typename Transformer_, std::size_t arguments_>
    requires((sizeof...(Types_) % arguments_) == 0)
    using Transform = /* xieite::types::List<...> */;

    template<std::size_t count_>
    using Repeat = /* xieite::types::List<...> */;

    template<typename... OtherTypes_>
    using Zip = /* xieite::types::List<...> */;

    template<typename Range_>
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
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

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
