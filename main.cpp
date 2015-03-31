#include <thread>	// for sleep_for()
#include <chrono>	// for second()
#include <cmath>	// for sqrt()

#include <iostream>

//#define NO_TIME_ELAPSED_MEASUREMENT
#include "TimeElapsed.hpp"

void slow_function(int t = 2)
{
	std::this_thread::sleep_for(std::chrono::seconds(t));
}

int main(void)
{
	float f;

	// 1. Easy to use
	TIME_ELAPSED(slow_function());

	// 2. Can refer to the caller environment by lambda [&]
	f = 1.0f;
	TIME_ELAPSED(f += sqrtf(f));
	std::cout << "f = " << f << std::endl;

	// 3. With the number of cycles: 500000 times
	f = 1.0f;
	TIME_ELAPSED_N(500000, f += sqrtf(f));
	std::cout << "f = " << f << std::endl;


	// 4. Can pass a code block: m and n can live only within (...)
	f = 1.0f;
	TIME_ELAPSED(

		int m = 3, n = 4;
		for (int i = 0; i < m*n; i++) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			f++;
		}

	);
	std::cout << "f = " << f << std::endl;

	// 5. Repeating: this code block runs three times
	TIME_ELAPSED_N(3,

		int k = 2;
		for (int i = 0; i < k; i++) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			f++;
		}

	);
	std::cout << "f = " << f << std::endl;

	// 6. A distinct line can be the line header by itself
	TIME_ELAPSED_EXP(f = cosh(f));

	// 7. Your custom header
	TIME_ELAPSED_MARKER("My Header 1",

		for (int i = 0; i < 2; i++) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}

	);

	// 7. Your custom header with repetition
	TIME_ELAPSED_MARKER_N(2, "My Location 2",

		std::this_thread::sleep_for(std::chrono::seconds(1));

	);

	return 0;
}
