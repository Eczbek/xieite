# xieite::console::StyleResetLock
Declared in `<xieite/console/StyleResetLock.hpp>`

<br/>

A helper class for automatically resetting the foreground, background, and effects in console when it is destructed.

<br/><br/>

## Constructor
```cpp
StyleResetLock() noexcept = default;
```

## Destructor
```cpp
~StyleResetLock();
```
