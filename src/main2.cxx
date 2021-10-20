#pragma region headers {
	#include <iostream>
	#include <string>
	#include <exception>

	// #include <bitset>
	#define _USE_MATH_DEFINES
	#include <math.h>
	#include <limits>
	#include <tuple>
	#include <array>
	#include <vector>
	#include <functional>

	#pragma region visualization {
		#include <vtkPlotArea.h>

		#include <vtkAxis.h>
		#include <vtkChartXY.h>
		#include <vtkContextScene.h>
		#include <vtkContextView.h>
		#include <vtkFloatArray.h>
		#include <vtkNamedColors.h>
		#include <vtkNew.h>
		#include <vtkPen.h>
		#include <vtkPlot.h>
		#include <vtkProperty.h>
		#include <vtkRenderWindow.h>
		#include <vtkRenderWindowInteractor.h>
		#include <vtkRenderer.h>
		#include <vtkTable.h>
	#pragma endregion } visualization
#pragma endregion } headers

#pragma region declarations { 
	namespace looney {
		namespace math {
			#pragma region classes {
				class number;
				class integer;
				class rational;
				class real;
				class scientific;

				class function;	
				
				class tensor;
				class complex;
				class quarternion;
				class octonion;
			#pragma endregion } classes
			#pragma region namespaces {
				namespace logic {

				};
				namespace numeric {
					class derivative;
					class integral;

					namespace approximation {
						class series_expansion;
					};
				};

				namespace symbolic {
					class derivative;
					class integral;

					namespace approximation {
						class series_expansion;
					};
				};
				namespace datum {};
			#pragma endregion } namespaces
			#pragma region functions {
				number operator"" _num(unsigned long long);
				integer operator"" _int(unsigned long long);
				rational operator"" _rat(unsigned long long);
				real operator"" _rea(unsigned long long);
				scientific operator"" _sci(long double);

				std::ostream& operator<<(std::ostream& os, const looney::math::number& num);
				std::ostream& operator<<(std::ostream& os, const looney::math::integer& num);
				std::ostream& operator<<(std::ostream& os, const looney::math::rational& num);
				std::ostream& operator<<(std::ostream& os, const looney::math::real& num);
				std::ostream& operator<<(std::ostream& os, const looney::math::scientific& num);
			#pragma endregion } functions
		};
	};
#pragma endregion } declarations
#pragma region definitions {
	class looney::math::number {
		public:
			typedef std::uint64_t value_t;
		private:
			value_t m_value;
		public:
			number();
			// number(const value_t& val);

			number inc(const number& other) const;
			number dec(const number& other) const;

			number add(const number& other) const;
			number sub(const number& other) const;

			number mul(const number& other) const;
			number div(const number& other) const;

			number pow(const number& other) const;
			number nrt(const number& other) const;
			number gol(const number& other) const;
			number log(const number& other) const;

			number spow(const number& other) const;
			number snrt(const number& other) const;
			number sgol(const number& other) const;
			number slog(const number& other) const;

			number operator()(const number& other, const char& degree = 0) const;

			friend number operator"" _num(unsigned long long val);
			friend std::ostream& operator<<(std::ostream& os, const number& num);
	};
	class looney::math::integer {
		public:
			typedef std::int64_t value_t;
		private:
			value_t m_value;
		public:
			integer();
			// integer (const value_t& val);

			integer inc(const integer& other) const;
			integer dec(const integer& other) const;

			integer add(const integer& other) const;
			integer sub(const integer& other) const;

			integer mul(const integer& other) const;
			integer div(const integer& other) const;

			integer pow(const integer& other) const;
			integer nrt(const integer& other) const;
			integer gol(const integer& other) const;
			integer log(const integer& other) const;

			integer spow(const integer& other) const;
			integer snrt(const integer& other) const;
			integer sgol(const integer& other) const;
			integer slog(const integer& other) const;

			integer operator()(const integer& other, const char& degree = 0) const;

			friend integer operator"" _int(unsigned long long val);
			friend std::ostream& operator<<(std::ostream& os, const integer& num);
	};
	class looney::math::rational {
		public:
			typedef float value_t;
		private:
			value_t m_value;
		public:
			rational();
			// rational (const value_t& val);

			rational inc(const rational& other) const;
			rational dec(const rational& other) const;

			rational add(const rational& other) const;
			rational sub(const rational& other) const;

			rational mul(const rational& other) const;
			rational div(const rational& other) const;

			rational pow(const rational& other) const;
			rational nrt(const rational& other) const;
			rational gol(const rational& other) const;
			rational log(const rational& other) const;

			rational spow(const rational& other) const;
			rational snrt(const rational& other) const;
			rational sgol(const rational& other) const;
			rational slog(const rational& other) const;

			rational operator()(const rational& other, const char& degree = 0) const;

			friend rational operator"" _rat(unsigned long long val);
			friend std::ostream& operator<<(std::ostream& os, const rational& num);
	};
	class looney::math::real {
		public:
			typedef double value_t;
		private:
			value_t m_value;
		public:
			real();
			// real (const value_t& val);

			real inc(const real& other) const;
			real dec(const real& other) const;

			real add(const real& other) const;
			real sub(const real& other) const;

			real mul(const real& other) const;
			real div(const real& other) const;

			real pow(const real& other) const;
			real nrt(const real& other) const;
			real gol(const real& other) const;
			real log(const real& other) const;

			real spow(const real& other) const;
			real snrt(const real& other) const;
			real sgol(const real& other) const;
			real slog(const real& other) const;

			real operator()(const real& other, const char& degree = 0) const;

			friend real operator"" _rea(unsigned long long val);
			friend std::ostream& operator<<(std::ostream& os, const real& num);
	};
	class looney::math::scientific {
		public:
			typedef long double value_t;
		private:
			value_t m_value;
		public:
			scientific();
			scientific (const value_t& val);

			scientific inc(const scientific& other) const;
			scientific dec(const scientific& other) const;

			scientific add(const scientific& other) const;
			scientific sub(const scientific& other) const;

			scientific mul(const scientific& other) const;
			scientific div(const scientific& other) const;

			scientific pow(const scientific& other) const;
			scientific nrt(const scientific& other) const;
			scientific gol(const scientific& other) const;
			scientific log(const scientific& other) const;

			scientific spow(const scientific& other) const;
			scientific snrt(const scientific& other) const;
			scientific sgol(const scientific& other) const;
			scientific slog(const scientific& other) const;

			scientific operator()(const scientific& other, const char& degree = 0) const;

			operator double() const;

			friend scientific operator"" _sci(long double val);
			friend std::ostream& operator<<(std::ostream& os, const scientific& num);
	};

	class looney::math::function {
		public:
			typedef double domain_t;
			typedef double range_t;

			typedef std::array<bool, 2> lbools_t;
			typedef std::array<domain_t, 2> _dlimits_t;
			typedef std::tuple<_dlimits_t, lbools_t> dlimits_t;
			typedef std::array<range_t, 2> _rlimits_t;
			typedef std::tuple<_rlimits_t, lbools_t> rlimits_t;

			typedef std::function<range_t(domain_t)> function_t;
		private:
			dlimits_t m_d;
			rlimits_t m_r;
			function_t m_f;
		public:
			function(const function_t &f);
			function(const function_t &f, const _dlimits_t& domain);
			function(const function_t &f, const dlimits_t& domain);
			function(const function_t &f, const _dlimits_t& domain, const _rlimits_t range);
			function(const function_t &f, const dlimits_t& domain, const rlimits_t range);

			bool in_domain(const domain_t& param);
			bool in_range(const domain_t& param);

			range_t operator()(const domain_t& param);
			
			friend void plot2d(const looney::math::function &_function);
	};
	// class tensor {
	// 	public:
	// 		typedef float value_t;
	// 		typedef std::vector<value_t> array_t;
	// 	private:
	// 		array_t m_dims;
	// 		array_t m_data;
	// 	public:
	// 		tensor();	
	// 		tensor(const array_t& data);
			
	// };
#pragma endregion } definitions
#pragma region implentations {
	#pragma region looney {
		#pragma region namespaces {
			#pragma region math {
				#pragma region classes {
					#pragma region number {
						looney::math::number::number() : m_value(0) {}
						// looney::math::number::number(const value_t& val) : m_value(val) {}
						looney::math::number
						looney::math::number::inc(const number& other) const
						{
							looney::math::number res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::number
						looney::math::number::dec(const number& other) const
						{
							number res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::number
						looney::math::number::add(const number& other) const
						{
							number res;
							res.m_value = m_value + other.m_value;
							return res;
						};
						looney::math::number
						looney::math::number::sub(const number& other) const
						{
							number res;
							res.m_value = m_value - other.m_value;
							return res;
						};
						looney::math::number
						looney::math::number::mul(const number& other) const
						{
							number res;
							res.m_value = m_value * other.m_value;
							return res;
						};
						looney::math::number
						looney::math::number::div(const number& other) const
						{
							number res;
							res.m_value = m_value / other.m_value;
							return res;
						};
						looney::math::number
						looney::math::number::pow(const number& other) const
						{
							number res;
							res.m_value = std::pow(m_value, other.m_value);
							return res;
						};
						looney::math::number
						looney::math::number::nrt(const number& other) const
						{
							number res;
							res.m_value = std::pow(m_value, 1.0/other.m_value);
							return res;
						};
						looney::math::number
						looney::math::number::gol(const number& other) const
						{
							number res;
							res.m_value = std::pow(other.m_value, m_value);
							return res;
						};
						looney::math::number
						looney::math::number::log(const number& other) const
						{
							number res;

							res.m_value = std::log(other.m_value)/std::log(m_value);
							return res;

						};
						looney::math::number
						looney::math::number::spow(const number& other) const
						{
							number res;

							res.m_value = 1;
							for(std::size_t it = 0; it < other.m_value; it++) {
								res = pow(res);
							}

							return res;
						};
						looney::math::number
						looney::math::number::snrt(const number& other) const
						{
							number res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::number
						looney::math::number::sgol(const number& other) const
						{
							number res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::number
						looney::math::number::slog(const number& other) const
						{
							number res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::number
						looney::math::number::operator()(
							const number& other,
							const char& degree
						) const {
							number res;
							char deg = std::abs(degree);
							
							// res = ( std::signbit(static_cast<float>(degree)) ? 
							// 	( deg == 0 ? dec(other) : 
							// 	( deg == 1 ? sub(other) :
							// 	( deg == 2 ? div(other) :
							// 	( deg == 3 ? nrt(other) :
							// 	( deg == 4 ? log(other) :
							// 	( deg == 5 ? _4nrt(other) : 
							// 	( deg == 6 ? _4log(other) :
							// 		std::nan("")
							// 	)))))))
							// :
							// 	( deg == 0 ? inc(other) :
							// 	( deg == 1 ? add(other) :
							// 	( deg == 2 ? mul(other) :
							// 	( deg == 3 ? pow(other) :
							// 	( deg == 4 ? exp(other) :
							// 	( deg == 5 ? _4pow(other) :
							// 	( deg == 6 ? _4exp(other) :
							// 		std::nan("")
							// 	)))))))
							// );
							return res;
						};
					#pragma endregion } number
					#pragma region integer {
						looney::math::integer::integer() : m_value(0) {}
						// looney::math::integer::integer(const value_t& val) : m_value(val) {}
						looney::math::integer
						looney::math::integer::inc(const integer& other) const
						{
							looney::math::integer res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::integer
						looney::math::integer::dec(const integer& other) const
						{
							integer res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::integer
						looney::math::integer::add(const integer& other) const
						{
							integer res;
							res.m_value = m_value + other.m_value;
							return res;
						};
						looney::math::integer
						looney::math::integer::sub(const integer& other) const
						{
							integer res;
							res.m_value = m_value - other.m_value;
							return res;
						};
						looney::math::integer
						looney::math::integer::mul(const integer& other) const
						{
							integer res;
							res.m_value = m_value * other.m_value;
							return res;
						};
						looney::math::integer
						looney::math::integer::div(const integer& other) const
						{
							integer res;
							res.m_value = m_value / other.m_value;
							return res;
						};
						looney::math::integer
						looney::math::integer::pow(const integer& other) const
						{
							integer res;
							res.m_value = std::pow(m_value, other.m_value);
							return res;
						};
						looney::math::integer
						looney::math::integer::nrt(const integer& other) const
						{
							integer res;
							res.m_value = std::pow(m_value, 1.0/other.m_value);
							return res;
						};
						looney::math::integer
						looney::math::integer::gol(const integer& other) const
						{
							integer res;
							res.m_value = std::pow(other.m_value, m_value);
							return res;
						};
						looney::math::integer
						looney::math::integer::log(const integer& other) const
						{
							integer res;

							res.m_value = std::log(other.m_value)/std::log(m_value);
							return res;

						};
						looney::math::integer
						looney::math::integer::spow(const integer& other) const
						{
							integer res;

							res.m_value = 1;
							for(std::size_t it = 0; it < other.m_value; it++) {
								res = pow(res);
							}

							return res;
						};
						looney::math::integer
						looney::math::integer::snrt(const integer& other) const
						{
							integer res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::integer
						looney::math::integer::sgol(const integer& other) const
						{
							integer res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::integer
						looney::math::integer::slog(const integer& other) const
						{
							integer res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::integer
						looney::math::integer::operator()(
							const integer& other,
							const char& degree
						) const {
							integer res;
							char deg = std::abs(degree);
							
							// res = ( std::signbit(static_cast<float>(degree)) ? 
							// 	( deg == 0 ? dec(other) : 
							// 	( deg == 1 ? sub(other) :
							// 	( deg == 2 ? div(other) :
							// 	( deg == 3 ? nrt(other) :
							// 	( deg == 4 ? log(other) :
							// 	( deg == 5 ? _4nrt(other) : 
							// 	( deg == 6 ? _4log(other) :
							// 		std::nan("")
							// 	)))))))
							// :
							// 	( deg == 0 ? inc(other) :
							// 	( deg == 1 ? add(other) :
							// 	( deg == 2 ? mul(other) :
							// 	( deg == 3 ? pow(other) :
							// 	( deg == 4 ? exp(other) :
							// 	( deg == 5 ? _4pow(other) :
							// 	( deg == 6 ? _4exp(other) :
							// 		std::nan("")
							// 	)))))))
							// );
							return res;
						};
					#pragma endregion } integer
					#pragma region rational {
						looney::math::rational::rational() : m_value(0) {}
						// looney::math::rational::rational(const value_t& val) : m_value(val) {}
						looney::math::rational
						looney::math::rational::inc(const rational& other) const
						{
							looney::math::rational res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::rational
						looney::math::rational::dec(const rational& other) const
						{
							rational res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::rational
						looney::math::rational::add(const rational& other) const
						{
							rational res;
							res.m_value = m_value + other.m_value;
							return res;
						};
						looney::math::rational
						looney::math::rational::sub(const rational& other) const
						{
							rational res;
							res.m_value = m_value - other.m_value;
							return res;
						};
						looney::math::rational
						looney::math::rational::mul(const rational& other) const
						{
							rational res;
							res.m_value = m_value * other.m_value;
							return res;
						};
						looney::math::rational
						looney::math::rational::div(const rational& other) const
						{
							rational res;
							res.m_value = m_value / other.m_value;
							return res;
						};
						looney::math::rational
						looney::math::rational::pow(const rational& other) const
						{
							rational res;
							res.m_value = std::pow(m_value, other.m_value);
							return res;
						};
						looney::math::rational
						looney::math::rational::nrt(const rational& other) const
						{
							rational res;
							res.m_value = std::pow(m_value, 1.0/other.m_value);
							return res;
						};
						looney::math::rational
						looney::math::rational::gol(const rational& other) const
						{
							rational res;
							res.m_value = std::pow(other.m_value, m_value);
							return res;
						};
						looney::math::rational
						looney::math::rational::log(const rational& other) const
						{
							rational res;

							res.m_value = std::log(other.m_value)/std::log(m_value);
							return res;

						};
						looney::math::rational
						looney::math::rational::spow(const rational& other) const
						{
							rational res;

							res.m_value = 1;
							for(std::size_t it = 0; it < other.m_value; it++) {
								res = pow(res);
							}

							return res;
						};
						looney::math::rational
						looney::math::rational::snrt(const rational& other) const
						{
							rational res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::rational
						looney::math::rational::sgol(const rational& other) const
						{
							rational res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::rational
						looney::math::rational::slog(const rational& other) const
						{
							rational res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::rational
						looney::math::rational::operator()(
							const rational& other,
							const char& degree
						) const {
							rational res;
							char deg = std::abs(degree);
							
							// res = ( std::signbit(static_cast<float>(degree)) ? 
							// 	( deg == 0 ? dec(other) : 
							// 	( deg == 1 ? sub(other) :
							// 	( deg == 2 ? div(other) :
							// 	( deg == 3 ? nrt(other) :
							// 	( deg == 4 ? log(other) :
							// 	( deg == 5 ? _4nrt(other) : 
							// 	( deg == 6 ? _4log(other) :
							// 		std::nan("")
							// 	)))))))
							// :
							// 	( deg == 0 ? inc(other) :
							// 	( deg == 1 ? add(other) :
							// 	( deg == 2 ? mul(other) :
							// 	( deg == 3 ? pow(other) :
							// 	( deg == 4 ? exp(other) :
							// 	( deg == 5 ? _4pow(other) :
							// 	( deg == 6 ? _4exp(other) :
							// 		std::nan("")
							// 	)))))))
							// );
							return res;
						};
					#pragma endregion } rational
					#pragma region real {
						looney::math::real::real() : m_value(0) {}
						// looney::math::real::real(const value_t& val) : m_value(val) {}
						looney::math::real
						looney::math::real::inc(const real& other) const
						{
							looney::math::real res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::real
						looney::math::real::dec(const real& other) const
						{
							real res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::real
						looney::math::real::add(const real& other) const
						{
							real res;
							res.m_value = m_value + other.m_value;
							return res;
						};
						looney::math::real
						looney::math::real::sub(const real& other) const
						{
							real res;
							res.m_value = m_value - other.m_value;
							return res;
						};
						looney::math::real
						looney::math::real::mul(const real& other) const
						{
							real res;
							res.m_value = m_value * other.m_value;
							return res;
						};
						looney::math::real
						looney::math::real::div(const real& other) const
						{
							real res;
							res.m_value = m_value / other.m_value;
							return res;
						};
						looney::math::real
						looney::math::real::pow(const real& other) const
						{
							real res;
							res.m_value = std::pow(m_value, other.m_value);
							return res;
						};
						looney::math::real
						looney::math::real::nrt(const real& other) const
						{
							real res;
							res.m_value = std::pow(m_value, 1.0/other.m_value);
							return res;
						};
						looney::math::real
						looney::math::real::gol(const real& other) const
						{
							real res;
							res.m_value = std::pow(other.m_value, m_value);
							return res;
						};
						looney::math::real
						looney::math::real::log(const real& other) const
						{
							real res;

							res.m_value = std::log(other.m_value)/std::log(m_value);
							return res;

						};
						looney::math::real
						looney::math::real::spow(const real& other) const
						{
							real res;

							res.m_value = 1;
							for(std::size_t it = 0; it < other.m_value; it++) {
								res = pow(res);
							}

							return res;
						};
						looney::math::real
						looney::math::real::snrt(const real& other) const
						{
							real res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::real
						looney::math::real::sgol(const real& other) const
						{
							real res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::real
						looney::math::real::slog(const real& other) const
						{
							real res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::real
						looney::math::real::operator()(
							const real& other,
							const char& degree
						) const {
							real res;
							char deg = std::abs(degree);
							
							// res = ( std::signbit(static_cast<float>(degree)) ? 
							// 	( deg == 0 ? dec(other) : 
							// 	( deg == 1 ? sub(other) :
							// 	( deg == 2 ? div(other) :
							// 	( deg == 3 ? nrt(other) :
							// 	( deg == 4 ? log(other) :
							// 	( deg == 5 ? _4nrt(other) : 
							// 	( deg == 6 ? _4log(other) :
							// 		std::nan("")
							// 	)))))))
							// :
							// 	( deg == 0 ? inc(other) :
							// 	( deg == 1 ? add(other) :
							// 	( deg == 2 ? mul(other) :
							// 	( deg == 3 ? pow(other) :
							// 	( deg == 4 ? exp(other) :
							// 	( deg == 5 ? _4pow(other) :
							// 	( deg == 6 ? _4exp(other) :
							// 		std::nan("")
							// 	)))))))
							// );
							return res;
						};
					#pragma endregion } real
					#pragma region scientific {
						looney::math::scientific::scientific() : m_value(0) {}
						looney::math::scientific::scientific(const value_t& val) : m_value(val) {}
						looney::math::scientific
						looney::math::scientific::inc(const scientific& other) const
						{
							looney::math::scientific res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::scientific
						looney::math::scientific::dec(const scientific& other) const
						{
							scientific res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::scientific
						looney::math::scientific::add(const scientific& other) const
						{
							scientific res;
							res.m_value = m_value + other.m_value;
							return res;
						};
						looney::math::scientific
						looney::math::scientific::sub(const scientific& other) const
						{
							scientific res;
							res.m_value = m_value - other.m_value;
							return res;
						};
						looney::math::scientific
						looney::math::scientific::mul(const scientific& other) const
						{
							scientific res;
							res.m_value = m_value * other.m_value;
							return res;
						};
						looney::math::scientific
						looney::math::scientific::div(const scientific& other) const
						{
							scientific res;
							res.m_value = m_value / other.m_value;
							return res;
						};
						looney::math::scientific
						looney::math::scientific::pow(const scientific& other) const
						{
							scientific res;
							res.m_value = std::pow(m_value, other.m_value);
							return res;
						};
						looney::math::scientific
						looney::math::scientific::nrt(const scientific& other) const
						{
							scientific res;
							res.m_value = std::pow(m_value, 1.0/other.m_value);
							return res;
						};
						looney::math::scientific
						looney::math::scientific::gol(const scientific& other) const
						{
							scientific res;
							res.m_value = std::pow(other.m_value, m_value);
							return res;
						};
						looney::math::scientific
						looney::math::scientific::log(const scientific& other) const
						{
							scientific res;

							res.m_value = std::log(other.m_value)/std::log(m_value);
							return res;

						};
						looney::math::scientific
						looney::math::scientific::spow(const scientific& other) const
						{
							long double _int, _rem;
							scientific res, rem;

							_rem = std::modfl(other.m_value, &_int);

							res.m_value = snrt(static_cast<scientific>(1.0/_rem));

							for(std::size_t it = 0; it < _int; it++) {
								res = pow(res);
							}
							

							return res;
						};
						looney::math::scientific
						looney::math::scientific::snrt(const scientific& other) const
						{
							long double _int, _rem;
							scientific res, guess;

							guess = 1;
							// need to define the numerical derivative
							// need a root solver.
							for(std::size_t it = 0; it < _int; it++) {
								res = pow(res);
							}

							return res;
						};
						looney::math::scientific
						looney::math::scientific::sgol(const scientific& other) const
						{
							scientific res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::scientific
						looney::math::scientific::slog(const scientific& other) const
						{
							scientific res;
							throw std::exception("not impplemented");
							return res;
						};
						looney::math::scientific
						looney::math::scientific::operator()(
							const scientific& other,
							const char& degree
						) const {
							scientific res;
							char deg = std::abs(degree);
							
							// res = ( std::signbit(static_cast<float>(degree)) ? 
							// 	( deg == 0 ? dec(other) : 
							// 	( deg == 1 ? sub(other) :
							// 	( deg == 2 ? div(other) :
							// 	( deg == 3 ? nrt(other) :
							// 	( deg == 4 ? log(other) :
							// 	( deg == 5 ? _4nrt(other) : 
							// 	( deg == 6 ? _4log(other) :
							// 		std::nan("")
							// 	)))))))
							// :
							// 	( deg == 0 ? inc(other) :
							// 	( deg == 1 ? add(other) :
							// 	( deg == 2 ? mul(other) :
							// 	( deg == 3 ? pow(other) :
							// 	( deg == 4 ? exp(other) :
							// 	( deg == 5 ? _4pow(other) :
							// 	( deg == 6 ? _4exp(other) :
							// 		std::nan("")
							// 	)))))))
							// );
							return res;
						};
						looney::math::scientific::operator double() const {
							return m_value;
						}
					#pragma endregion } scientific
					#pragma region function {
							looney::math::function::function(const function_t &f) :
								m_f(f),
								m_d(std::forward_as_tuple(
									_dlimits_t({
										-std::numeric_limits<domain_t>::infinity(),
										std::numeric_limits<domain_t>::infinity()
									}),
									lbools_t({false, false})
								)),
								m_r(std::forward_as_tuple(
									_rlimits_t({
										-std::numeric_limits<range_t>::infinity(),
										std::numeric_limits<range_t>::infinity()
									}),
									lbools_t({false, false})
								))
							{ }
							looney::math::function::function(const function_t &f) :
								m_f(f),
								m_d(std::forward_as_tuple(
									_dlimits_t({
										-std::numeric_limits<domain_t>::infinity(),
										std::numeric_limits<domain_t>::infinity()
									}),
									lbools_t({false, false})
								)),
								m_r(std::forward_as_tuple(
									_rlimits_t({
										-std::numeric_limits<range_t>::infinity(),
										std::numeric_limits<range_t>::infinity()
									}),
									lbools_t({false, false})
								))
							{ }

							// looney::math::function::function (
							// 	const function_t &f,
							// 	const _dlimits_t& domain,
							// 	const _rlimits_t range
							// );
							looney::math::function::function (
								const function_t &f,
								const dlimits_t& domain,
								const rlimits_t range
							) : m_f(f), m_d(domain), m_r(range) { }
							// function(const function_t &f, const _dlimits_t& domain);
							// function(const function_t &f, const dlimits_t& domain);

							looney::math::function::range_t
							looney::math::function::operator()(const domain_t& params) {
								return m_f(params);
							}
					#pragma endregion } function
					// class quarternion;
					// class complex;
					// class octonion;
				#pragma endregion } classes
				#pragma region functions {
					looney::math::number
					looney::math::operator"" _num(unsigned long long val) {
						looney::math::number num;
						num.m_value = val;
						return num;
					}
					looney::math::integer
					looney::math::operator"" _int(unsigned long long val) {
						looney::math::integer num;
						num.m_value = val;
						return num;
					}
					looney::math::rational
					looney::math::operator"" _rat(unsigned long long val) {
						looney::math::rational num;
						num.m_value = val;
						return num;
					}
					looney::math::real
					looney::math::operator"" _rea(unsigned long long val) {
						looney::math::real num;
						num.m_value = val;
						return num;
					}
					looney::math::scientific
					looney::math::operator"" _sci(long double val) {
						looney::math::scientific num;
						num.m_value = val;
						return num;
					}

					std::ostream&
					looney::math::operator<<(
						std::ostream& os,
						const looney::math::number& num
					)
					{
						os << num.m_value;
						return os;
					};
					std::ostream&
					looney::math::operator<<(
						std::ostream& os,
						const looney::math::integer& num
					)
					{
						os << num.m_value;
						return os;
					};
					std::ostream&
					looney::math::operator<<(
						std::ostream& os,
						const looney::math::rational& num
					)
					{
						os << num.m_value;
						return os;
					};
					std::ostream&
					looney::math::operator<<(
						std::ostream& os,
						const looney::math::real& num
					)
					{
						os << num.m_value;
						return os;
					};
					std::ostream&
					looney::math::operator<<(
						std::ostream& os,
						const looney::math::scientific& num
					)
					{
						os << num.m_value;
						return os;
					};
				#pragma endregion } functions
				#pragma region namespaces {
					#pragma region datum {
						namespace looney::math::datum {
							looney::math::number pi;
						};
					#pragma endregion } datum
				#pragma endregion } namaspaces
			#pragma endregion } math
		#pragma endregion } namespaces
	#pragma endregion } looney
#pragma endregion } implementaions

void vtk_chart_example() {
  vtkNew<vtkNamedColors> colors;

  // Create a table with some points in it.
  vtkNew<vtkTable> table;

  vtkNew<vtkFloatArray> arrX;
  arrX->SetName("X Axis");
  table->AddColumn(arrX);

  vtkNew<vtkFloatArray> arrC;
  arrC->SetName("Cosine");
  table->AddColumn(arrC);

  vtkNew<vtkFloatArray> arrS;
  arrS->SetName("Sine");
  table->AddColumn(arrS);

  // Fill in the table with some example values.
  int numPoints = 69;
  float inc = 7.5 / (numPoints - 1);
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i)
  {
    table->SetValue(i, 0, i * inc);
    table->SetValue(i, 1, cos(i * inc));
    table->SetValue(i, 2, sin(i * inc));
  }

  // Set up the view
  vtkNew<vtkContextView> view;
  view->GetRenderWindow()->SetWindowName("LinePlot");
  // view->GetRenderer()->SetBackground(colors->GetColor3d("SlateGray").GetData());

  // Add multiple line plots, setting the colors etc.
  vtkNew<vtkChartXY> chart;
  view->GetScene()->AddItem(chart);
	vtkPlot* line = chart->AddPlot(vtkChart::LINE);
	line->SetInputData(table, 0, 1);
	line->SetColor(0, 255, 0, 255);
	line->SetWidth(1.0);
	line = chart->AddPlot(vtkChart::LINE);
	line->SetInputData(table, 0, 2);
	line->SetColor(255, 0, 0, 255);
	line->SetWidth(5.0);

  // For dotted line, the line type can be from 2 to 5 for different dash/dot
  // patterns (see enum in vtkPen containing DASH_LINE, value 2):
  // #ifndef WIN32
  //   line->GetPen()->SetLineType(vtkPen::DASH_LINE);
  // #endif
  // (ifdef-ed out on Windows because DASH_LINE does not work on Windows
  //  machines with built-in Intel HD graphics card...)

  view->GetRenderWindow()->SetMultiSamples(0);

  // Start interactor
  view->GetRenderWindow()->Render();
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

};
void plot(
	std::function<double(double)> callback,
	std::array<double, 2> domain,
	std::array<double, 2> range
) {
  vtkNew<vtkNamedColors> colors;

  // Create a table with some points in it.
  vtkNew<vtkTable> table;

  vtkNew<vtkFloatArray> arrX;
  arrX->SetName("X Axis");
  table->AddColumn(arrX);

  vtkNew<vtkFloatArray> arrY;
  arrY->SetName("Y Axis");
  table->AddColumn(arrY);


  // Fill in the table with some example values.
  int numPoints = 10000;
  float inc = (domain[1] - domain[0]) / (numPoints - 1);
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i)
  {
    table->SetValue(i, 0, i * inc + domain[0]);
    table->SetValue(i, 1, callback(i * inc + domain[0]));
  }

  // Set up the view
  vtkNew<vtkContextView> view;
  view->GetRenderWindow()->SetWindowName("LinePlot");
  // view->GetRenderer()->SetBackground(colors->GetColor3d("SlateGray").GetData());

  // Add multiple line plots, setting the colors etc.
  vtkNew<vtkChartXY> chart;
  view->GetScene()->AddItem(chart);
	vtkPlot* line = chart->AddPlot(vtkChart::LINE);
	
	line->SetInputData(table, 0, 1);
	line->SetColor(0, 0, 0, 255);
	line->GetPen()->SetLineType(vtkPen::SOLID_LINE);
	line->SetWidth(1.1);
	line->GetYAxis()->SetRange(range[0], range[1]);
  // For dotted line, the line type can be from 2 to 5 for different dash/dot
  // patterns (see enum in vtkPen containing DASH_LINE, value 2):
  // #ifndef WIN32
  //   line->GetPen()->SetLineType(vtkPen::DASH_LINE);
  // #endif
  // (ifdef-ed out on Windows because DASH_LINE does not work on Windows
  //  machines with built-in Intel HD graphics card...)

	chart->SetPoint1(0,1);
	chart->SetPoint2(0,1);

  view->GetRenderWindow()->SetMultiSamples(0);

  // Start interactor
  view->GetRenderWindow()->Render();
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

};
void looney::math::plot2d(const looney::math::function &_function) {
	std::array<double, 2> domain;
	std::array<double, 2> range;
	std::function<double(double)> callback;

	domain = std::get<0>(_function.m_d);
	range = std::get<0>(_function.m_r);
	callback = _function.m_f;
	
	plot(callback, domain, range);
}
int main(
	int argc,
	char const *argv[]
)
{
	using namespace looney::math;
	function f([](double x){
		return std::pow(x, 2.0);
	});

	plot2d(f);	

	//
	// std::cout << a << "\n";
	// std::cout << "End of program. (press any key to continue... )" << std::endl;
	// std::cin.get();
	return 0;
}
