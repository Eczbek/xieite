# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[Mixfix<Return(LeftArgument, RightArgument)>](../../../mixfix.md)\:\:Intermediate\<\> \{\}
Defined in fragment [xieite:functors.Mixfix](../../../../../../src/functors/mixfix.cpp)

&nbsp;

## Description
An intermediate state for an mixfix thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename LeftArgumentReference>
struct Intermediate {
    constexpr Intermediate(const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>&, LeftArgumentReference&&) noexcept;

    auto operator=(const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>&) = delete;

    template<std::convertible_to<RightArgument> RightArgumentReference>
    friend constexpr Return operator>(xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>&&, RightArgumentReference&&);
};
```
- [Intermediate\(\)](./structures/intermediate/1/operators/constructor.md)
- [operator>\(\)](./structures/intermediate/1/operators/more.md)

&nbsp;

## [Example](./operators/less.md#Example)
