# [xieite](../xieite.md)::[concepts](../concepts.md)::Hashable
Defined in header [<xieite/concepts/Hashable.hpp>](../../include/xieite/concepts/Hashable.hpp)

<br/>

Specifies that a type is hashable, or that `std::hash` has a specification for it

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Hashable = requires(Any value) {
	{ std::hash<Any>()(value) } -> std::convertible_to<std::size_t>;
};
```
### Template parameters
- `Any` - Any type
