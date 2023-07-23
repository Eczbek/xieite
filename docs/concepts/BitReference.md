# [xieite](../xieite.md)::[concepts](../concepts.md)::BitReference
Defined in header [<xieite/concepts/BitReference.hpp>](../../include/xieite/concepts/BitReference.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept BitReference = requires(Any any) {
	{ any.~Any() };
	{ any = std::declval<bool>() } -> std::same_as<Any&>;
	{ any = std::declval<Any>() } -> std::same_as<Any&>;
	{ static_cast<bool>(any) } -> std::same_as<bool>;
	{ ~any } -> std::same_as<bool>;
	{ any.flip() } -> std::same_as<Any&>;
};
```
### Template parameters
- `Any` - Any type

<br/><br/>

## Example
```cpp
#include <bitset>
#include <iostream>
#include <xieite/concepts/BitReference.hpp>

int main() {
	std::bitset<8> bitset;
	auto bit = bitset[0];

	std::cout << std::boolalpha
		<< xieite::concepts::BitReference<decltype(bit)> << '\n';
}
```
Output:
```
true
```
