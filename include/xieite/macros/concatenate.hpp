#pragma once

#define XIEITE_CONCATENATE(first, second) XIEITE_CONCATENATE_INTERNAL(first, second)

#define XIEITE_CONCATENATE_INTERNAL(first, second) first##second
