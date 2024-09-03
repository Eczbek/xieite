# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:FunctionPointer\<\> \{\}
Defined in fragment [xieite:traits.FunctionPointer](../../../src/traits/function_pointer.cpp)

&nbsp;

## Description
Provides information about function pointers and member function pointers. See definitions for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct FunctionPointer;
```
#### 2..5)
```cpp
template<typename Return, typename... Arguments>
struct FunctionPointer<Return(*)(Arguments... /* , ... */) /* noexcept */> {
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
struct FunctionPointer<Return(Class::*)(Arguments... /* , ... */) /* const */ /* volatile */ /* & */ /* && */ /* noexcept */> {
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
    using Info = xieite::traits::FunctionPointer<decltype(&Foo::bar)>;

    std::println("{}", Info::variadic);
    std::println("{}", Info::constantQualified);
    std::println("{}", Info::volatileQualified);
    std::println("{}", Info::leftValueQualified);
    std::println("{}", Info::rightValueQualified);
    std::println("{}", Info::NoThrowQualified);
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
