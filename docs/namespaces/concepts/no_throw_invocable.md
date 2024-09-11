# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowInvocable\<\>
Defined in fragment [xieite:concepts.NoThrowInvocable](../../../src/concepts/no_throw_invocable.cpp)

&nbsp;

## Description
Specifies that a type is invocable with arguments and returns a type without throwing exceptions; basically a wrapper for `std::is_nothrow_invocable_r_v`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, typename Signature>
concept NoThrowInvocable = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto lambda = [] {
        throw std::runtime_error("nope");
    };

    std::println("{}", xieite::concepts::NoThrowInvocable<decltype(lambda)>);
}
```
Output:
```
false
```
