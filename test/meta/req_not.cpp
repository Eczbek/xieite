#include <xte/meta/req_not.hpp>

template<typename T>
concept C = false;

static_assert(xte::req_not<int, []<C>{}>);
