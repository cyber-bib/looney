#pragma once

#include "series.fxx"

class looney::math::series: public function {
  public:
    double m_exponent;
    series();
    range_t operator()(const domain_t &domain);
};