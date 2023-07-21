# [xieite](../xieite.md)::[concepts](../concepts.md)::BitsetReference
Defined in header [<xieite/concepts/BitsetReference.hpp>](../../include/xieite/concepts/BitsetReference.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept BitsetReference = requires(Any any) {
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
#include <xieite/concepts/BitsetReference.hpp>

int main() {
	std::bitset<8> bitset;
	auto bit = bitset[0];

	std::cout << std::boolalpha
		<< xieite::concepts::BitsetReference<decltype(bit)> << '\n';
}
```
Output:
```
true
```
