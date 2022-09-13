# gcufl::regex::email
Declared in `<gcufl/regex/email.hpp>`
```cpp
const std::regex email("^(([\\w+\\-~=\\/{}\\(\\)]+|\"([^\"]|\\\\\")+\")(\\.[\\w+\\-~=\\/{}\\(\\)]+|\"([^\"]|\\\\\")+\")*)@([\\w\\-\\(\\)]+(\\.[\\w\\(\\)]+)+|\\[\\d{1,3}(\\.\\d{1,3}){3}\\])$");
```
A constant regex for checking the validity of an email, works for most cases.
## Example
```cpp
#include <gcufl/regex/email.hpp>
#include <iostream>
#include <regex>

int main() {
	std::cout << std::boolalpha << std::regex_match("bob@mail.com", gcufl::regex::email) << '\n';
}
```
Output:
```
true
```
