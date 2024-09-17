# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:tupleify\<\>\(\)
Defined in fragment [xieite:containers.tupleify](../../../src/containers/tupleify.cpp)

&nbsp;

## Description
Constructs a tuple from an aggregate structure.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Aggregate Structure>
[[nodiscard]] constexpr auto tupleify(Structure&& value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo {
	int x;
	double y;
	char z;
};

int main() {
    auto foo = xieite::containers::tupleify(Foo(1, 2.5, 'a'));

    std::apply([](auto... values) { std::println("{}", values); }, foo);
}
```
Output:
```
1
2.5
a
```
