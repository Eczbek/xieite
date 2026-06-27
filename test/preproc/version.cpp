#include <xte/preproc/version.hpp>

static_assert(XTE_VERSION_MAJOR >= 0);
static_assert(XTE_VERSION_MINOR >= 0);
static_assert(XTE_VERSION_PATCH >= 0);
static_assert(XTE_VERSION(>=, 0, 128));
