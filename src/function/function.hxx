#pragma once

#include "function.fxx"

namespace looney::math {
  class function_domain {
    public:
      typedef double value_t;
      typedef std::vector<value_t> type;
      
      typedef std::array<value_t, 2> bound_t;
      typedef std::array<bool, 2> interval_t;
      typedef std::tuple<value_t, bound_t, interval_t> epack_t;
      typedef std::vector<epack_t> vpack_t;
    public:
      // static value_t ninf();
      // static function_domain ninf(std::size_t size);
      static value_t inf();
      static value_t nan();
      static bound_t default_bounds();
      // static function_domain inf(std::size_t size);
      // static function_domain nan(std::size_t size);
    private:
      vpack_t m_pack;
    public:
      function_domain() = default;
      // function_domain(const type &dvals);
      function_domain& operator=(const type &dvals);
      operator bool() const;
    friend class function;
    friend void ::plot2d(const looney::math::function &_function);
  };
  class function_range {
    public:
      typedef double value_t;
      typedef std::vector<value_t> type;
      
      typedef std::array<value_t, 2> bound_t;
      typedef std::array<bool, 2> interval_t;
      typedef std::tuple<value_t, bound_t, interval_t> epack_t;

      typedef std::vector<epack_t> vpack_t;
    public:
      // static value_t ninf();
      // static function_range ninf(std::size_t size);
      static value_t inf();
      static value_t nan();
      static bound_t default_bounds();
      // static function_range inf(std::size_t size);
      // static function_range nan(std::size_t size);
    private:
      vpack_t m_pack;
    public:
      function_range() = default;
      // function_range(const type &rvals);
      function_range& operator=(const type &rvals);
      operator bool() const;
      operator type() const;
    
    friend class function;
    friend void ::plot2d(const looney::math::function &_function);
  };
  class function {
    #pragma region aliases {
      public:
        typedef std::array<std::size_t, 2> argc_t;
        typedef std::array<bool, 2> interval_t;
        typedef std::function<function_range::type(const function_domain::type&)> function_t;
    #pragma endregion } aliases 
    #pragma region variables {
      private:
        argc_t m_argc;

        function_domain m_domain;
        function_range m_range;
        function_t m_function;

        function_range m_default;
        function_range::value_t m_range_default_val;
    #pragma endregion } variables

    public:
      function(
        const argc_t &argc = {1, 1},
        const function_t &f = [](const function_domain::type &x){ return x; },
        const function_domain::bound_t &dbounds = {-function_domain::inf(), function_domain::inf()},
        const function_range::bound_t &rbounds = {-function_range::inf(), function_range::inf()},
        const interval_t &interval = {false, false},
        const function_range::value_t &_default = function_range::nan()
      );

      function& operator()(const function_domain::type& argv);
      operator function_range::type() const;
      
      friend void ::plot2d(const looney::math::function &_function);
  };

  class 
};