#pragma once

#include "stack.hpp"

namespace ds {
  template < typename T >
  class mono_list : public stack< T > { };
} // namespace ds
