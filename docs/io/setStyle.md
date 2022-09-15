# gcufl::io::setStyle
Declared in `<gcufl/io/setStyle.hpp>`
```cpp
template<gcufl::io::escapeCodes::Background B, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
void setStyle() noexcept;

template<gcufl::io::escapeCodes::Effect E, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
void setStyle() noexcept;

template<gcufl::io::escapeCodes::Foreground F, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
void setStyle() noexcept;

template<gcufl::io::escapeCodes::Effect E, gcufl::io::escapeCodes::Foreground F, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
void setStyle() noexcept;

template<gcufl::io::escapeCodes::Effect E, gcufl::io::escapeCodes::Foreground F, gcufl::io::escapeCodes::Background B, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
void setStyle() noexcept;
```
