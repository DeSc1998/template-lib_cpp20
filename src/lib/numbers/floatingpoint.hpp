
#pragma once

#include <array>
#include <concepts>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

template < size_t Base = 10, size_t Presision = 16 >
class floatingpoint {
  bool is_negativ = false;
  std::array< size_t, Presision > digits; // significant digits
  std::wstring symbols = L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  static void distribute( floatingpoint& f ) { }

public:
  floatingpoint() = default;
  floatingpoint( const floatingpoint& other );
  floatingpoint( floatingpoint&& other );

  template < std::integral I >
  floatingpoint( I value );

  floatingpoint& operator=( const floatingpoint& other );
  floatingpoint& operator=( floatingpoint&& other );

  template < std::integral I >
  floatingpoint& operator=( I value );
};
