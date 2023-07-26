# [xieite](../xieite.md)::[functors](../functors.md)::MakeFunctor
Defined in header [<xieite/functors/MakeFunctor.hpp>](../../include/xieite/functors/MakeFunctor.hpp)

<br/>

A wrapper for any type which defines `operator()` if it does not exist

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Derivable Any>
struct MakeFunctor
: Any {
	constexpr MakeFunctor(const Any&);

	constexpr void operator()(xieite::types::Anything) const;
};
```
### Template parameters
- `Any` - Any type satisfying `xieite::concepts::Derivable`
### Public members
<pre><code>MakeFunctor/
|- <a href="./MakeFunctor1/constructor.md">MakeFunctor</a>
`- <a href="./MakeFunctor1/operatorCall.md">operator()</a>
</code></pre>

<br/><br/>

```cpp
template<xieite::concepts::Derivable Function>
requires std::invocable<Function, xieite::types::Anything>
struct MakeFunctor<Function>
: Function {
	constexpr MakeFunctor(const Function&);

	using Function::operator();
};
```
### Template parameters
- `Function` - Any type satisfying `xieite::concepts::Derivable`
### Requirements
- `Function` must be invocable with a `xieite::types::Anything`
### Public members
<pre><code>MakeFunctor/
|- <a href="./MakeFunctor2/constructor.md">MakeFunctor</a>
`- <a href="./MakeFunctor2/operatorCall.md">operator()</a>
</code></pre>
