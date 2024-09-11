# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:FunctionPointerTraits\<\> \{\}
Defined in fragment [xieite:types.FunctionPointerTraits](../../../src/types/function_pointer_traits.cpp)

&nbsp;

## Description
Provides information about function pointers and member function pointers. See definitions for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct FunctionPointerTraits;
```
#### 2..5)
```cpp
template<typename Return, typename... Arguments>
struct FunctionPointerTraits<Return(*)(Arguments... /* , ... */) /* noexcept */> {
    using Function = Return(*)(Arguments... /* , ... */) /* noexcept */;
    using Return = Return;
    using Arguments = std::tuple<Arguments...>;

    static constexpr bool variadic = /* ... */;
    static constexpr bool NoThrowQualified = /* ... */;
};
```
#### 6..54)
```cpp
template<typename Return, typename Class, typename... Arguments>
struct FunctionPointerTraits<Return(Class::*)(Arguments... /* , ... */) /* const */ /* volatile */ /* & */ /* && */ /* noexcept */> {
    using Class = Class;
    using Reference = /* volatile */ /* const */ Class /* & */ /* && */;
    using Function = Return(Class::*)(Arguments... /* , ... */) /* const */ /* volatile */ /* & */ /* && */ /* noexcept */;
    using Return = Return;
    using Arguments = std::tuple<Arguments...>;

    static constexpr bool variadic = /* ... */;
    static constexpr bool constantQualified = /* ... */;
    static constexpr bool volatileQualified = /* ... */;
    static constexpr bool leftValueQualified = /* ... */;
    static constexpr bool rightValueQualified = /* ... */;
    static constexpr bool NoThrowQualified = /* ... */;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo {
    void bar(int, char) const & noexcept {}
};

int main() {
    using Traits = xieite::types::FunctionPointerTraits<decltype(&Foo::bar)>;

    std::println("{}", Traits::variadic);
    std::println("{}", Traits::constantQualified);
    std::println("{}", Traits::volatileQualified);
    std::println("{}", Traits::leftValueQualified);
    std::println("{}", Traits::rightValueQualified);
    std::println("{}", Traits::NoThrowQualified);
}
```
Output:
```
false
true
false
true
false
true
```
