#include <iostream>
#include <vector>

#pragma region forward-declarations { 
	namespace dexter {
		namespace math {
			class number;
			class integer;
			class rational;
			class real;
			class scientific;
			
			class tensor;
			class complex;
			class quarternion;
			class octonion;

			namespace analytic {
				class function;
				class polynomial;

				class derivative;
				class integral;

				namespace approximation {
					class series_expansion;
				};
			};
			namespace numeric {
				class function;

				class derivative;
				class integral;

				namespace approximation {
					class series_expansion;
				};
			};
		};
	};
#pragma endregion } forward-declarations
#pragma region class-definitions {
	class dexter::math::number {
		public:
			typedef std::int64_t value_t;
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
			number exp(const number& other) const;
			number log(const number& other) const;

			number _4pow(const number& other) const;
			number _4nrt(const number& other) const;
			number _4exp(const number& other) const;
			number _4log(const number& other) const;

			number operator()(const number& other, const char& degree = 0) const;

			friend std::ostream& operator<<(std::ostream& os, const number& num);
	};
#pragma endregion } class-definitions

#pragma region class-implentations {
	dexter::math::number::number() : m_value(0) {}
	// dexter::math::number::number(const value_t& val) : m_value(val) {}
	dexter::math::number
	dexter::math::number::inc(const number& other) const
	{
		dexter::math::number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::dec(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::add(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::sub(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::mul(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::div(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::pow(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::nrt(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::exp(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::log(const number& other) const
	{
		number res;

		return res;

	};
	dexter::math::number
	dexter::math::number::_4pow(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::_4nrt(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::_4exp(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::_4log(const number& other) const
	{
		number res;

		return res;
	};
	dexter::math::number
	dexter::math::number::operator()(
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

			// friend operator<<(std::ostream& os, const number& num);

#pragma endregion } class-implementaions
int main(
	int argc,
	char const *argv[]
)
{
	dexter::math::number a, b, c;

	a = b.add(c);

	std::cout << "End of program. (press any key to continue... )" << std::endl;
	std::cin.get();
	return 0;
}
