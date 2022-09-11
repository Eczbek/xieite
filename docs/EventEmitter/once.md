# gcufl::EventEmitter<K>::once
Declared in `<gcufl/EventEmitter.hpp>`
```cpp
template <typename... P, std::invocable<P...> C>
void once(const K& event, const C& callback) noexcept;
```
Creates an temporary event by key with parameters.
<br/>
The created event can only be used once.
