# xieite::random::InterruptableUniformDistribution
Defined in header `<xieite/random/InterruptableUniformDistribution.hpp>`

<br/>

A uniform random number distribution which allows excluding subintervals from the main interval.

<br/><br/>

## Template Parameters
```cpp
template<xieite::concepts::Arithmetic Number>
```

## Constructors
```cpp
InterruptableUniformDistribution(const Number begin, const Number end, const std::vector<std::pair<Number, Number>>& interruptions);
```

## Operators
```cpp
[[nodiscard]]
Number operator()(xieite::concepts::UniformRandomBitGenerator auto&& generator) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <random> // std::mt19937, std::random_device
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
