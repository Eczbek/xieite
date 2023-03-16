# xieite::concepts::Hashable
Defined in header `<xieite/concepts/Hashable.hpp>`

<br/>

Specifies that a type can be hashed using `std::hash`.

<br/><br/>

## Declarations
```cpp
template<typename Any>
concept Hashable = requires(Any value) {
	{ std::hash<Any>()(value) } -> std::convertible_to<std::size_t>;
};
```
