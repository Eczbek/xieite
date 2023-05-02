# [`XIEITE`](../../docs/macros.md)`_THIEF_...`
Defined in header [`<xieite/macros/THIEF.hpp>`](../../include/xieite/macros/THIEF.hpp)

<br/>

Uses magic to steal private members of classes.

<br/><br/>

## Synopses

<br/>

```cpp
#define XIEITE_THIEF_EXPOSE(item, id) \
	constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_STEAL, id)(); \
	template<auto pointer> struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF, id) { \
		friend constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_STEAL, id)() { \
			return pointer; \
		} \
	}; \
	template struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF, id)<item>;
```
### Parameters
- `item` - A reference or pointer to the member to steal
- `id` - An ID for this operation

<br/>

```cpp
#define XIEITE_THIEF_STEAL(victim, id) \
	((victim).*XIEITE_CONCATENATE(XIEITE_INTERNAL_STEAL, id)())
```
### Parameters
- `victim` - An instance of the class to steal from
- `id` - The ID for the operation

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/THIEF.hpp>

class Victim {
private:
	int value = 42;
};

XIEITE_THIEF_EXPOSE(&Victim::value, heist);

int main() {
	Victim victim;

	std::cout << XIEITE_THIEF_STEAL(victim, heist) << '\n';
}
```
Output:
```
42
```
