# [xieite](../../README.md)::[functions](../functions.md)::OptionalCallOperator
Defined in header [<xieite/functions/OptionalCallOperator.hpp>](../../include/xieite/functions/OptionalCallOperator.hpp)

<br/>

A wrapper for any type which defines `operator()` if it does not exist

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
### Public members
<pre><code>OptionalCallOperator/
|- <a href="./OptionalCallOperator/constructor1.md">OptionalCallOperator</a>
`- <a href="./OptionalCallOperator/operatorCall1.md">operator()</a>
</code></pre>

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
### Public members
<pre><code>OptionalCallOperator/
|- <a href="./OptionalCallOperator/constructor2.md">OptionalCallOperator</a>
`- <a href="./OptionalCallOperator/operatorCall2.md">operator()</a>
</code></pre>
