#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;
	{
		ft::set<int>	set1;
		ft::set<int>	set2;
		for (int i = 0; i < 100; ++i)
			set1.insert(i);
		for (int i = 0; i < 100; ++i)
			set2.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set1 == set2);
		ft_time = clock() - t;
		std::set<int>	set3;
		std::set<int>	set4;
		for (int i = 0; i < 100; ++i)
			set3.insert(i);
		for (int i = 0; i < 100; ++i)
			set4.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set3 == set4);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	{
		ft::set<int>	set1;
		ft::set<int>	set2;
		for (int i = 0; i < 100; ++i)
			set1.insert(i);
		for (int i = 0; i < 99; ++i)
			set2.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set1 == set2);
		ft_time = clock() - t;
		std::set<int>	set3;
		std::set<int>	set4;
		for (int i = 0; i < 100; ++i)
			set3.insert(i);
		for (int i = 0; i < 99; ++i)
			set4.insert(i * 2);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set3 == set4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::set<int>	set1;
		ft::set<int>	set2;
		for (int i = 0; i < 100; ++i)
			set1.insert(i);
		for (int i = 0; i < 100; ++i)
			set2.insert(i * 2);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set1 >= set2);
		ft_time = clock() - t;
		std::set<int>	set3;
		std::set<int>	set4;
		for (int i = 0; i < 100; ++i)
			set3.insert(i);
		for (int i = 0; i < 100; ++i)
			set4.insert(i * 2);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set3 >= set4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::set<int>	set1;
		ft::set<int>	set2;
		for (int i = 0; i < 100; ++i)
			set1.insert(i);
		for (int i = 0; i < 100; ++i)
			set2.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set1 < set2);
		ft_time = clock() - t;
		std::set<int>	set3;
		std::set<int>	set4;
		for (int i = 0; i < 100; ++i)
			set3.insert(i);
		for (int i = 0; i < 100; ++i)
			set4.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set3 < set4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::set<int>	set1;
		ft::set<int>	set2;
		for (int i = 0; i < 100; ++i)
			set1.insert(i);
		for (int i = 0; i < 99; ++i)
			set2.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set1 < set2);
		ft_time = clock() - t;
		std::set<int>	set3;
		std::set<int>	set4;
		for (int i = 0; i < 100; ++i)
			set3.insert(i);
		for (int i = 0; i < 99; ++i)
			set4.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set3 < set4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}
	{
		ft::set<int>	set1;
		ft::set<int>	set2;
		for (int i = 0; i < 100; ++i)
			set1.insert(i);
		for (int i = 0; i < 100; ++i)
			set2.insert(i * 2);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set1 < set2);
		ft_time = clock() - t;
		std::set<int>	set3;
		std::set<int>	set4;
		for (int i = 0; i < 100; ++i)
			set3.insert(i);
		for (int i = 0; i < 100; ++i)
			set4.insert(i * 2);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			(void)(set3 < set4);
		std_time = clock() - t;
		std::cout << "\t\t\t\t";
		efficiency_output(ft_time, std_time);
	}

	return 0;
}