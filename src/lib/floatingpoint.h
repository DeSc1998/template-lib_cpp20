#pragma once

#include <ostream>
#include <string>
#include <utility>
#include <vector>

template < size_t Base >
class floatingpoint {
  bool is_negativ = false;
  std::vector< size_t > digets_pos, digets_neg;
  std::wstring symbols = L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  static void distribute( floatingpoint& f ) { }

public:
  floatingpoint() = default;
};
