
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>


void selectionSort(std::vector<int>& list)
{
	if (list.size() < 2) return;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		auto minIt = std::min_element(it, list.end());
		if (minIt != it)
			std::swap(*it, *minIt);
	}
}


 void insertionSort(std::vector<int> &list)
{
	 if (list.size() < 2) return;
	 for (size_t i = 1; i < list.size(); i++)
	 {
		 const auto itCurrent = list.begin() + i;
		 const auto insertPos = std::upper_bound(list.begin(), list.begin() + i, *itCurrent);
		 if (itCurrent != insertPos)
		 {
			 std::rotate(insertPos, itCurrent, itCurrent + 1);
		 }
	 }
	 
}


void bubbleSort(std::vector<int> &list) 
{
	if (list.size() < 2) return;
	std::size_t n = list.size();
	bool swapped = true;
	while (swapped) 
	{
		swapped = false;
		for (size_t i = 0; i < n - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				std::swap(list[i], list[i + 1]);
				swapped = true;
			}
		}
		n--;
		if (!swapped)
		{
			break;
		}
	}
	
}


void printVec(std::vector<int> &list)
{
	for (auto element : list)
	{

		std::cout << element << " ";
	}
}

int main()
{
	auto unsorted = { 25,17,32,56,25,19,8,66,29,6,20,29 };
	auto list = std::vector<int>{ unsorted };

	selectionSort(list);
	std::cout << "Selection Sort: ";
	printVec(list);
	std::cout << std::endl;

	insertionSort(list);
	std::cout << "Insertion Sort: ";
	printVec(list);
	std::cout << std::endl;

	bubbleSort(list);
	std::cout << "Bubble Sort: ";
	printVec(list);
	std::cout << std::endl;
}








