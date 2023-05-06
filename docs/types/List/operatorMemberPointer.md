# [`xieite`](../../../README.md)`::`[`types`](../../../docs/types.md)`::`[`List<Types...>`](../../../docs/types/List.md)`::operator->*`
Defined in header [`<xieite/types/List.hpp>`](../../../include/xieite/types/List.hpp)

<br/>

For use in `xieite::types::Set`.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<typename Type>
constexpr auto operator->*(const xieite::types::List<Type>) -> std::conditional_t<(std::is_same_v<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>>;
```
### Template parameters
- `Type` - Any type
### Parameters
- An unnamed copy of `xieite::types::List` of `Type`
### Return type
- If at least one of `Types...` is `Type`, then a `xieite::types::List` of `Types...`, otherwise of `Types...` and `Type`
