# [`xieite`](../../README.md)`::`[`types`](../../docs/types.md)`::List`
Defined in header [`<xieite/types/List.hpp>`](../../include/xieite/types/List.hpp)

<br/>

A simple class which exists only to store types.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename... Types>
struct List final {
	using Data = std::tuple<Types...>;

	template<typename Type>
	constexpr std::conditional_t<(std::same_as<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(xieite::types::List<Type>) const noexcept;
};
```
### Template parameters
- `Types...` - Any types
### Member types
- [`Data`](../../docs/types/List/Data.md)
### Member functions
- [`operator->*`](../../docs/types/List/operatorMemberPointer.md)
