#ifndef FAKER_COMMON_SPAN_H
#define FAKER_COMMON_SPAN_H

#ifdef FAKER_USE_STD_SPAN

#include <span>

namespace faker::utils {
template <typename T> using span = std::span<T>;
}

#else

#include "tcb_span.h"

namespace faker::utils {
template <typename T> using span = tcb::span<T>;
}

#endif

#endif