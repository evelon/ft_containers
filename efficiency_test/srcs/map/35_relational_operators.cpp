#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;
	{
		ft::map<int, std::string>	map1;
		ft::map<int, std::string>	map2;
		for (int i = 0; i < 100; ++i)
			map1[i] = "string";
		for (int i = 0; i < 100; ++i)
			map2[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map1 == map2);
		ft_time = clock() - t;
		std::map<int, std::string>	map3;
		std::map<int, std::string>	map4;
		for (int i = 0; i < 100; ++i)
			map3[i] = "string";
		for (int i = 0; i < 100; ++i)
			map4[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map3 == map4);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	{
		ft::map<int, std::string>	map1;
		ft::map<int, std::string>	map2;
		for (int i = 0; i < 100; ++i)
			map1[i] = "string";
		for (int i = 0; i < 99; ++i)
			map2[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map1 == map2);
		ft_time = clock() - t;
		std::map<int, std::string>	map3;
		std::map<int, std::string>	map4;
		for (int i = 0; i < 100; ++i)
			map3[i] = "string";
		for (int i = 0; i < 99; ++i)
			map4[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map3 == map4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::map<int, std::string>	map1;
		ft::map<int, std::string>	map2;
		for (int i = 0; i < 100; ++i)
			map1[i] = "string";
		for (int i = 0; i < 100; ++i)
			map2[i] = "test";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map1 >= map2);
		ft_time = clock() - t;
		std::map<int, std::string>	map3;
		std::map<int, std::string>	map4;
		for (int i = 0; i < 100; ++i)
			map3[i] = "string";
		for (int i = 0; i < 100; ++i)
			map4[i] = "test";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map3 >= map4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::map<int, std::string>	map1;
		ft::map<int, std::string>	map2;
		for (int i = 0; i < 100; ++i)
			map1[i] = "string";
		for (int i = 0; i < 100; ++i)
			map2[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map1 < map2);
		ft_time = clock() - t;
		std::map<int, std::string>	map3;
		std::map<int, std::string>	map4;
		for (int i = 0; i < 100; ++i)
			map3[i] = "string";
		for (int i = 0; i < 100; ++i)
			map4[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map3 < map4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::map<int, std::string>	map1;
		ft::map<int, std::string>	map2;
		for (int i = 0; i < 100; ++i)
			map1[i] = "string";
		for (int i = 0; i < 99; ++i)
			map2[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map1 < map2);
		ft_time = clock() - t;
		std::map<int, std::string>	map3;
		std::map<int, std::string>	map4;
		for (int i = 0; i < 100; ++i)
			map3[i] = "string";
		for (int i = 0; i < 99; ++i)
			map4[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map3 < map4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::map<int, std::string>	map1;
		ft::map<int, std::string>	map2;
		for (int i = 0; i < 100; ++i)
			map1[i] = "string";
		for (int i = 0; i < 100; ++i)
			map2[i] = "test";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map1 < map2);
		ft_time = clock() - t;
		std::map<int, std::string>	map3;
		std::map<int, std::string>	map4;
		for (int i = 0; i < 100; ++i)
			map3[i] = "string";
		for (int i = 0; i < 100; ++i)
			map4[i] = "test";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(map3 < map4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}

	return 0;
}