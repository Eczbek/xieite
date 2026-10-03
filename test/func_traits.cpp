#include <xte/func_traits.hpp>
#include <xte/qual_traits.hpp>

static_assert(xte::is_const_func<int() const>);
static_assert(xte::is_const_func<int() const volatile & noexcept>);
static_assert(!xte::is_const_func<int()>);



static_assert(xte::is_volatile_func<int() volatile>);
static_assert(xte::is_volatile_func<int() const volatile & noexcept>);
static_assert(!xte::is_volatile_func<int()>);



// TODO: other concepts



static_assert(xte::is_same<int() const& noexcept, xte::add_const_func<int() & noexcept>>);



// TODO: other modifiers



static_assert(xte::is_same<int() const volatile&& noexcept, xte::add_cv_rvalue_ref_func<int() noexcept>>);
static_assert(xte::is_same<int() const volatile&& noexcept, xte::add_cv_rvalue_ref_func<int() noexcept>>);
static_assert(xte::is_same<int() const volatile&& noexcept, xte::add_cv_rvalue_ref_func<int() & noexcept>>);
