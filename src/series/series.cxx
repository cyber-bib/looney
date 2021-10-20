#include "series.hxx"

namespace looney::math {
  series::series() : function([&m_exponent](domain_t x){ return std::pow(x, m_exponent); }, 0) {};
};