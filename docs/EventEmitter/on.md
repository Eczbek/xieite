# gcufl::EventEmitter<K>::on
Declared in `<gcufl/EventEmitter.hpp>`
```cpp
template <typename... P, std::invocable<P...> C>
void on(const K& event, const C& callback) noexcept;
```
Creates an event by key with parameters.
