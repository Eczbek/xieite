# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[ProcessGuard](../../../../process_guard.md)\:\:ProcessGuard\<\>\(\)
Defined in fragment [xieite:functors.ProcessGuard](../../../../../../../src/functors/process_guard.cpp)

&nbsp;

## Description
Constructs a `xieite::functors::ProcessGuard`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::invocable<> Functor, auto = [] {}>
ProcessGuard(Functor&& callback) noexcept;
```

&nbsp;

## [Example](../../../../process_guard.md#Example)
