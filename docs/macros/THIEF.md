# [`XIEITE`](../../docs/macros.md)`_THIEF_...`
Defined in header [`<xieite/macros/THIEF.hpp>`](../../include/xieite/macros/THIEF.hpp)

<br/>

Uses cursed C++ magic to steal private members of classes.

<br/><br/>

## Synopses

<br/><br/>

```cpp
#define XIEITE_THIEF_EXPOSE(item, id) \
	constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)(); \
	template<auto pointer> struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_EXPOSE_, id) { \
		friend constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)() { \
			return pointer; \
		} \
	}; \
	template struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_EXPOSE_, id)<&item>;
```
### Parameters
- `item` - A reference or pointer to the member to steal
- `id` - An simple ID for this operation

<br/><br/>

```cpp
#define XIEITE_THIEF_STEAL(victim, id) \
	((victim).*XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)())
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

XIEITE_THIEF_EXPOSE(Victim::value, heist);

int main() {
	Victim victim;

	std::cout << XIEITE_THIEF_STEAL(victim, heist) << '\n';
}
```
Output:
```
42
```
