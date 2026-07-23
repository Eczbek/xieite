#include <xte/trait/add_cv_rvalue_ref_func.hpp>
#include <xte/trait/is_same.hpp>

struct A {};

static_assert(xte::is_same<int() const volatile&& noexcept, xte::add_cv_rvalue_ref_func<int() noexcept>>);
static_assert(xte::is_same<int(A::*)() const volatile&& noexcept, xte::add_cv_rvalue_ref_func<int(A::*)() noexcept>>);
static_assert(xte::is_same<int() const volatile& noexcept, xte::add_cv_rvalue_ref_func<int() & noexcept>>);
