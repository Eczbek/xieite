# [xieite](../../README.md)::[random](../random.md)::UniformInterruptableDistribution
Defined in header [<xieite/random/UniformInterruptableDistribution.hpp>](../../include/xieite/random/UniformInterruptableDistribution.hpp)

<br/>

A uniform random number distribution which allows excluding subintervals from the main interval

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
struct UniformInterruptableDistribution {
	UniformInterruptableDistribution(xieite::math::Interval<Number>, const xieite::concepts::RangeOf<xieite::math::Interval<Number>> auto&);

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

	auto interval = xieite::math::Interval<int>(0, 5);

	std::vector<xieite::math::Interval<int>> interruptions {
		xieite::math::Interval<int>(1, 4)
	};

	auto dist = xieite::random::UniformInterruptableDistribution<int>(interval, interruptions);

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
