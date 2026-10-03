#include <xte/meta/req.hpp>

template<typename>
concept C = false;

static_assert(xte::req_not<int, []<C>{}>);
