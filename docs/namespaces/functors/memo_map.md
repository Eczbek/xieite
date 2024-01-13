# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:MemoMap
Defined in header [<xieite/functors/memo_map.hpp>](../../../include/xieite/functors/memo_map.hpp)

&nbsp;

## Description
A thing.

(For use in `xieite::functors::memoize`)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Value, typename FirstKey, typename... RestKeys>
struct MemoMap {
	const Value& set(Value&&, FirstKey&&, RestKeys&&...);

	const Value& get(FirstKey&&, RestKeys&&...) const;

	bool has(FirstKey&&, RestKeys&&...) const;
};
```
##### Member functions
- [set](./structures/memo_map/1/set.md)
- [get](./structures/memo_map/1/set.md)
- [has](./structures/memo_map/1/set.md)
#### 2)
```cpp
template<typename Value, typename Key>
struct MemoMap<Value, Key> {
	const Value& set(Value&&, Key&&);

	const Value& get(Key&&) const;

	bool has(Key&&) const;
};
```
- [set](./structures/memo_map/2/set.md)
- [get](./structures/memo_map/2/set.md)
- [has](./structures/memo_map/2/set.md)
