# [`xieite`](../../README.md)`::`[`functions`](../../docs/functions.md)`::OptionalCallOperator`
Defined in header [`<xieite/functions/OptionalCallOperator.hpp>`](../../include/xieite/functions/OptionalCallOperator.hpp)

<br/>

A wrapper for any type which defines `operator()` if it does not exist.

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Derivable Any>
struct OptionalCallOperator
: Any {
	constexpr OptionalCallOperator(const Any&);

	constexpr void operator()(xieite::types::Anything) const;
};
```
### Template parameters
- `Any` - Any type satisfying `xieite::concepts::Derivable`
### Member functions
- [`OptionalCallOperator`](../../docs/functions/OptionalCallOperator/constructor1.md)
- [`operator()`](../../docs/functions/OptionalCallOperator/operatorCall1.md)

<br/><br/>

```cpp
template<xieite::concepts::Derivable Function>
requires(std::invocable<Function, xieite::types::Anything>)
struct OptionalCallOperator<Function>
: Function {
	constexpr OptionalCallOperator(const Function&);

	using Function::operator();
};
```
### Template parameters
- `Function` - Any type satisfying `xieite::concepts::Derivable`
### Requirements
- `Function` must be invocable with a `xieite::types::Anything`
### Member functions
- [`OptionalCallOperator`](../../docs/functions/OptionalCallOperator/constructor2.md)
- [`operator()`](../../docs/functions/OptionalCallOperator/operatorCall2.md)

<br/><br/>

## See also
- [`xieite::concepts::Derivable`](../../docs/concepts/Derivable.md)
