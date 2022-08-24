# gcufl::time::weekDays
```cpp
constexpr std::array<std::string_view, 7> weekDays { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
```
A constant array of week-day names.
## Example
```cpp
#include <iostream>
#include <gcufl/time.hpp>

int main() {
	std::cout << gcufl::time::weekDays[4] << '\n';
}
```
Output:
```
Thursday
```
