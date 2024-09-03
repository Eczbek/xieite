# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Polymorphic\<\>
Defined in fragment [xieite:concepts.Polymorphic](../../../src/concepts/polymorphic.cpp)

&nbsp;

## Description
Specifies that a type is polymorphic. Can be used for checking if a type has a virtual-table.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Polymorphic = std::is_polymorphic_v<Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo {
    void test() {}
};

struct Bar {
    virtual void test();
};

int main() {
    std::println("{}", xieite::concepts::Polymorphic<Foo>);
    std::println("{}", xieite::concepts::Polymorphic<Bar>);
}
```
Output:
```
false
true
```
