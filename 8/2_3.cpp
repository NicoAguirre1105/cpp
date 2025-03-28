#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include <cmath>
#include<fstream>
#include <sstream> 
using namespace std;
using namespace std::chrono;
const int n = 10000;

int block_size(int threads)
{
	return n / threads + (n % threads ? 1 : 0);
}

int Sum(string s)
{
	stringstream st;
	long long int sum = 0;
	int x;
	st << s; 
	while (st >> x) 
		sum = sum + x;
	return sum;
}

int Sum_thread(string s, int threads, int first_index){
	int bl_size = min(block_size(threads), n - first_index);
	int last_index = first_index + bl_size - 1;
	if (first_index != 0) {
		if (s[first_index - 1] == ' ') first_index--;
		while (first_index <= n - 1 and s[first_index] != ' ')
			first_index++;
	}
	while (last_index < n - 1 and s[last_index] != ' ') 
		last_index++;
	if (first_index <= last_index){
		string task = s.substr(first_index, last_index - first_index + 1);
		return Sum(task);
	}
	return 0;


}

void MultiThreadSum(string s, int threads)
{
	vector<future <int>> fut(threads);
	int s_size = s.size();
	int bl_size = block_size(threads);
	int first_index = 0;
	int i = 0;
	long long int ans = 0;

	while (first_index < s_size)
	{
		fut[i] = async(Sum_thread, s, threads, first_index);
		first_index += bl_size;
		i++;
	}
	for (int j = 0; j < i; ++j)
		ans += fut[j].get();
	cout << ans << endl;
}

int main()
{
	srand(time(0));
	string s;
	while (s.size() < n) {
		s += to_string(rand() % 10000) + " ";
	}
	s = s.substr(0, n);

	cout << "1 thread" << endl;
	int threads = 1;
	auto start = steady_clock::now();
	MultiThreadSum(s, threads);
	auto finish = steady_clock::now();

	cout << duration_cast <milliseconds> (finish - start).count() << "ms " << endl << endl;

	cout << "8 threads" << endl;
	threads = 8;
	start = steady_clock::now();
	MultiThreadSum(s, threads);
	finish = steady_clock::now();

	cout << duration_cast <milliseconds> (finish - start).count() << "ms " << endl;
}