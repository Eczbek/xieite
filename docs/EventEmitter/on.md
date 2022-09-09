# `gcufl::EventEmitter<K>::on`
Defined in `<gcufl/EventEmitter.hpp>`
<br/><br/>
```cpp
template <typename... P, std::invocable<P...> C>
void on(const K& event, const C& callback) noexcept;
```
Creates an event by key with parameters.
