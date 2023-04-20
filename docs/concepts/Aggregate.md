# `xieite::concepts::Aggregate`
Defined in header [`<xieite/concepts/Aggregate.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/concepts/Aggregate.hpp)

<br/>

Specifies that type `Any` is an aggregate.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Aggregate = std::is_aggregate_v<Any>;
```
### Template parameters
- `Any` - Any type
