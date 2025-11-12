
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>


std::list<int> SelectionSort1(std::vector<int> unsorted)
{
	std::vector<int>::iterator first = unsorted.begin();
	std::vector<int>::iterator last = unsorted.end();

	for (size_t i = 0; i < size(unsorted); i++)
	{
		std::vector<int>::iterator min_index = std::min_element(first, last);
		std::swap(unsorted[i], *min_index);
		++first;
	}
	
	return std::list<int>(unsorted.begin(), unsorted.end());
}

std::list<int> result{};
std::list<int>::iterator it;
std::list<int> SelectionSort2(std::vector<int> unsorted)
{
	if (size(result) == 0)
	{
		result.push_back(unsorted[0]);
		unsorted.erase(unsorted.begin());
	}
	for (it = result.begin(); it != result.end(); it++)
	{
		for (size_t i = 0; i < size(unsorted); i++) 
		{
			result.push_back(unsorted[0]);
			result.sort();
			unsorted.erase(unsorted.begin());
		}
		
	}
	return result;
}
	


std::list<int> SelectionSort3(std::vector<int> unsorted) 
{
	std::size_t n = unsorted.size();
	bool swapped = true;
	while (swapped) 
	{
		swapped = false;
		for (size_t i = 0; i < n - 1; i++)
		{
			if (unsorted[i] > unsorted[i + 1])
			{
				std::swap(unsorted[i], unsorted[i + 1]);
				swapped = true;
			}
		}
		n--;
		if (!swapped)
		{
			break;
		}
	}
	
	return std::list<int>(unsorted.begin(), unsorted.end());
}


int main()
{
	std::vector<int> unsorted = { 25,17,32,56,25,19,8,66,29,6,20,29 };

	std::list<int> sorted = SelectionSort1(unsorted);
	std::cout << "result1: ";
	for (int value : sorted)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;

	std::list<int> result = SelectionSort2(unsorted);
	std::cout << "result2: ";
	for (int value : result)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;

	sorted = SelectionSort3(unsorted);
	std::cout << "result3: ";
	for (int value : sorted)
	{
		std::cout << value << " ";
	}

}










