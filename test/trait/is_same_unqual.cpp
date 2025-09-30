#include <xte/trait/is_same_unqual.hpp>

static_assert(xte::is_same_unqual<int, int>);
static_assert(xte::is_same_unqual<const int, int>);
static_assert(xte::is_same_unqual<volatile int, int>);
static_assert(xte::is_same_unqual<volatile const int, int>);
static_assert(xte::is_same_unqual<int, const int>);
static_assert(xte::is_same_unqual<const int, const int>);
static_assert(xte::is_same_unqual<volatile int, const int>);
static_assert(xte::is_same_unqual<volatile const int, const int>);
static_assert(xte::is_same_unqual<int, volatile int>);
static_assert(xte::is_same_unqual<const int, volatile int>);
static_assert(xte::is_same_unqual<volatile int, volatile int>);
static_assert(xte::is_same_unqual<volatile const int, volatile int>);
static_assert(xte::is_same_unqual<int, volatile const int>);
static_assert(xte::is_same_unqual<const int, volatile const int>);
static_assert(xte::is_same_unqual<volatile int, volatile const int>);
static_assert(xte::is_same_unqual<volatile const int, volatile const int>);

static_assert(not xte::is_same_unqual<int, int&>);
