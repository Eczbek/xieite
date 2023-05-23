# [`xieite`](../../../README.md)`::`[`functions`](../../../docs/functions.md)`::`[`Infix<Result, Parameter>`](../../../docs/functions/Infix.md)`::Infix`
Defined in header [`<xieite/functions/Infix.hpp>`](../../../include/xieite/functions/Infix.hpp)

<br/>

Constructs a `xieite::functions::Infix` thing.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Infix(const xieite::concepts::Functional<Result(Parameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` of `Result` of `Parameter`

<br/><br/>

## See also
- [`xieite::concepts::Functional`](../../../docs/concepts/Functional.md)
