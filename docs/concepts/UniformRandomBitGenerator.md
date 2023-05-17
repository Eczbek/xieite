# [`xieite`](../../README.md)`::`[`concepts`](../../docs/concepts.md)`::UniformRandomBitGenerator`
Defined in header [`<xieite/concepts/UniformRandomBitGenerator.hpp>`](../../include/xieite/UniformRandomBitGenerator.hpp)

<br/>

Specifies that type `Any` is a uniform random bit generator.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept UniformRandomBitGenerator = std::uniform_random_bit_generator<std::remove_reference_t<Any>>;
```
### Template parameters
- `Any` - Any type
