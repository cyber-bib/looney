#include "function.hxx"

namespace looney::math {
  #pragma region function_domain {
    function_domain::value_t
    function_domain::inf() {
      return std::numeric_limits<function_domain::value_t>::infinity();
    }
    function_domain::value_t
    function_domain::nan() {
      return std::nan("");
    }
    function_domain::bound_t
    function_domain::default_bounds() {
      return {-1*inf(), inf()};
    }
    // function_domain::function_domain(const type &dvals) {
    // }
    function_domain& function_domain::operator=(const type &dvals) {
      if(dvals.size() != m_pack.size()) {
        throw std::exception("out of bounds");
      }
      for(std::size_t it = 0; it < m_pack.size(); it++) {
        std::get<0>(m_pack.at(it)) = dvals.at(it);
      }

      return *this;
    }
    function_domain::operator bool() const
    {
      bool res = true;
      value_t v;
      bound_t b;
      interval_t i;

      for(std::size_t it = 0; it < m_pack.size(); it++) {
        std::tie(v, b, i) = m_pack.at(it);
        res =  i[0] ? (b[0] <= v) : (b[0] < v);
        res = (i[1] ? (v <= b[1]) : (v < b[1])) && res;
        if(!res) { continue; }
      }

      return res;
    }
  #pragma endregion } function_domain
  #pragma region function_range {
    function_range::value_t
    function_range::inf() {
      return std::numeric_limits<function_range::value_t>::infinity();
    }
    function_range::value_t
    function_range::nan() {
      return std::nan("");
    }
    function_range::bound_t
    function_range::default_bounds() {
      return {-1*inf(), inf()};
    }
    // function_range::function_range(const type &rvals) {
    // }
    function_range& function_range::operator=(const type &rvals) {
      if(rvals.size() != m_pack.size()) {
        throw std::exception("out of bounds");
      }
      for(std::size_t it = 0; it < m_pack.size(); it++) {
        std::get<0>(m_pack.at(it)) = rvals.at(it);
      }

      return *this;
    }
    function_range::operator bool() const
    {
      bool res = true;
      value_t v;
      bound_t b;
      interval_t i;

      for(std::size_t it = 0; it < m_pack.size(); it++) {
        std::tie(v, b, i) = m_pack.at(it);
        res =  i[0] ? (b[0] <= v) : (b[0] < v);
        res = (i[1] ? (v <= b[1]) : (v < b[1])) && res;
        if(!res) { continue; }
      }

      return res;
    }
    function_range::operator type() const {
      type res(m_pack.size());
      for(std::size_t it = 0; it < m_pack.size(); it++) {
        res.at(it) = std::get<0>(m_pack.at(it));
      }

      return res;
    }
  #pragma endregion } function_range
  #pragma region function {
    #pragma region [con/de]structo(s) {
      // function::function(const argc_t &argc) : m_argc(argc) {
      // }
      function::function(
        const argc_t &argc,
        const function_t &f,
        const function_domain::bound_t &dbounds,
        const function_range::bound_t &rbounds,
        const interval_t &interval,
        const function_range::value_t &_default
      ) :
        m_argc(argc),
        m_function(f),
        m_range_default_val(_default)
      {
        function_domain::epack_t dpack_e(function_domain::nan(), dbounds, interval);
        function_domain::epack_t rpack_e(m_range_default_val, rbounds, interval);

        m_domain.m_pack.assign(argc[0], dpack_e);
        m_range.m_pack.assign(argc[1], rpack_e);
        m_default.m_pack.assign(argc[1], rpack_e);
      }
    #pragma endregion } [con/de]structo(s)
    function&
    function::operator()(const function_domain::type& argv) {
      m_domain = argv;
      m_range = m_function(argv);
      m_range = ((m_domain && m_range) ? m_range : m_default);
      return (*this);
    }
    function::operator function_range::type() const {
      return m_range;

      // return ((m_domain && m_range) ?
      //   static_cast<function_range::type>(m_range) :
      //   function_range::type(m_range.m_pack.size(), m_range_default_val)
      // );
    }
  #pragma endregion } function

};