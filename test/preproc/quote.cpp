#include <xte/preproc/quote.hpp>
#include <string_view>

using namespace std::literals;

static_assert(XTE_QUOTE(abc) == "abc"sv);
