# gcufl::time::months
```cpp
constexpr std::array<std::string_view, 12> months { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
```
A constant array of month names.
## Example
```cpp
#include <iostream>
#include <gcufl/time>

int main() {
	std::cout << gcufl::time::months[3] << '\n';
}
```
Output:
```
April
```
