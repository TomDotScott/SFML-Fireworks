#pragma once
namespace constants
{
	static const int k_screenWidth{ 1280 };
	static const int k_screenHeight{ 720 };


	static int random_range(const int _min, const int _max) {
		return _min + rand() % ((_max + 1) - _min);
	}
}