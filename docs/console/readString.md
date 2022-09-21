# gcufl::console::readString
Declared in `<gcufl/console/readString.hpp>`
```cpp
std::string readString(const std::streamsize count = std::numeric_limits<std::streamsize>::max(), const char until = std::char_traits<char>::eof()) noexcept;
```
Reads a string from the `std::cin` buffer.
