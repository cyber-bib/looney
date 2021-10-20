#include "function.hxx"
#include "vtk-interface.hxx"


int main(
	int argc,
	char const *argv[]
)
{
	using namespace looney::math;

	function a({1, 1}, [](const function_domain::type &x){
		function_range::type y(x.size());
		y[0] = std::pow(x[0], 2.0);
		return y;
	}, {-1, 1}, {-1, 1}, {false, false}, 0);

	// function a([](function_domain::type x){ return std::pow(x); }, {-1, 1}, {-1, 1});

	// auto x = function_domain::type(1, 2);
	// auto y = static_cast<function_range::type>(a(x));
	// std::cout << y[0] << "\n";

	plot2d(a);
	std::cout << "End of program. (press any key to continue... )" << std::endl;
  std::cin.get();
	return 0;
}