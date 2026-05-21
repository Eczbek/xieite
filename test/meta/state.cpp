#include <xte/meta/state.hpp>

constexpr auto state = xte::state<>.set<0>;
static_assert(state.set<-~state.get<>>.get<> == 1);
static_assert(state.set<-~state.get<>>.get<> == 2);
static_assert(state.set<-~state.get<>>.get<> == 3);
