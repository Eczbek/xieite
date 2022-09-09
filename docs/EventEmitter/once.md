# gcufl::EventEmitter<K>::once
Defined in `<gcufl/EventEmitter.hpp>`
<br/><br/>
```cpp
template <typename... P, std::invocable<P...> C>
void once(const K& event, const C& callback) noexcept;
```
Creates an temporary event by key with parameters.
<br/>
The created event can only be used once.
