# [xieite](../../README.md)::[random](../random.md)::UniformInterruptableDistribution
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../include/xieite/random/UniformInterruptableDistribution.hpp)

<br/>

A uniform random number distribution which allows excluding subintervals from the main interval

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
struct UniformInterruptableDistribution final {
	UniformInterruptableDistribution(Number, Number, const xieite::concepts::RangeOf<std::pair<Number, NUmber>> auto&);

	Integral operator()(xieite::concepts::UniformRandomBitGenerator auto&) const;
};
```
### Template Parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Public members
<pre><code>UniformInterruptableDistribution/
|- <a href="./UniformInterruptableDistribution/constructor.md">UniformInterruptableDistribution</a>
`- <a href="./UniformInterruptableDistribution/operatorCall.md">operator()</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <random>
#include <xieite/random/UniformInterruptableDistribution.hpp>

int main() {
	auto rng = std::default_random_engine(std::random_device {}());

	std::vector<std::pair<int, int>> interruptions {
		{ 1, 4 }
	};

	auto dist = xieite::random::UniformInterruptableDistribution<int>(0, 5, interruptions);

	for (int i = 0; i < 10; ++i) {
		std::cout << dist(rng) << '\n';
	}
}
```
Possible output:
```
0
5
5
5
0
0
5
5
0
5
```
