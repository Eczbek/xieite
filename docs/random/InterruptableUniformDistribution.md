# xieite::random::InterruptableUniformDistribution
Declared in `<xieite/random/InterruptableUniformDistribution.hpp>`

<br/>

A uniform random number distribution which allows excluding subintervals from the main interval.

<br/><br/>

## Template parameters
`N` - either `std::integral` or `std::floating_point`.

## Constructor
```cpp
constexpr InterruptableUniformDistribution(const N begin, const N end, const std::vector<std::pair<N, N>>& interruptions);
```

## Operators
```cpp
template<xieite::concepts::UniformRandomGenerator G>
constexpr N operator()(G& generator) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <random>
#include <xieite/random/InterruptableUniformDistribution.hpp>

int main() {
	std::mt19937 rng(std::random_device {}());

	xieite::random::InterruptableUniformDistribution<int> dist(0, 5, { { 1, 4 } });

	for (int i = 0; i < 10; ++i)
		std::cout << dist(rng) << '\n';
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