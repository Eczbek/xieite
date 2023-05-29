# [xieite](../../README.md)::[functions](../functions.md)::DefaultCallOperator
Defined in header [<xieite/functions/DefaultCallOperator.hpp>](../../include/xieite/functions/DefaultCallOperator.hpp)

<br/>

A wrapper for any type which defines `operator()` if it does not exist

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Derivable Any>
struct DefaultCallOperator
: Any {
	constexpr DefaultCallOperator(const Any&);

	constexpr void operator()(xieite::types::Anything) const;
};
```
### Template parameters
- `Any` - Any type satisfying `xieite::concepts::Derivable`
### Public members
<pre><code>DefaultCallOperator/
|- <a href="./DefaultCallOperator1/constructor.md">DefaultCallOperator</a>
`- <a href="./DefaultCallOperator1/operatorCall.md">operator()</a>
</code></pre>

<br/><br/>

```cpp
template<xieite::concepts::Derivable Function>
requires(std::invocable<Function, xieite::types::Anything>)
struct DefaultCallOperator<Function>
: Function {
	constexpr DefaultCallOperator(const Function&);

	using Function::operator();
};
```
### Template parameters
- `Function` - Any type satisfying `xieite::concepts::Derivable`
### Requirements
- `Function` must be invocable with a `xieite::types::Anything`
### Public members
<pre><code>DefaultCallOperator/
|- <a href="./DefaultCallOperator2/constructor.md">DefaultCallOperator</a>
`- <a href="./DefaultCallOperator2/operatorCall.md">operator()</a>
</code></pre>
