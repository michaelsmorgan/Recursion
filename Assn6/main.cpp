#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "TestCases.hpp"

std::string collapseSpaces(std::string s);
std::vector<std::string> split(std::string s);
bool isPalindrome(std::string word, int start, int end);
bool isWordSymmetric(const std::vector<std::string>& words, int start, int end);
long vectorSum(const std::vector<int>& data, unsigned int position);
int vectorMin(const std::vector<int>& data, unsigned int position);
void quickSort(std::vector<int>& data, int start, int end);

int main()
{
	TestCases::runTestCases();
}

// ------------------------------------------------------------------
//
// Provided code to remove spaces from a string (and capitalize it)
//
// ------------------------------------------------------------------
std::string collapseSpaces(std::string s)
{
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
	std::transform(s.begin(), s.end(), s.begin(), toupper);	// Capitalize all
	return s;
}

// ------------------------------------------------------------------
//
// Solution string split code
//
// ------------------------------------------------------------------
std::vector<std::string> split(std::string s)
{
	std::istringstream is(s);
	std::vector<std::string> words;

	do
	{
		std::string word;
		is >> word;
		if (word.length() > 0)
		{
			words.push_back(word);
		}
	} while (is);

	return words;
}

bool isPalindrome(std::string word, int start, int end)
{
	if (start >= end) return true;
	if (word[start] == word[end]) return isPalindrome(word, start + 1, end - 1);
	return false;
}

// ------------------------------------------------------------------
//
// Provided quicksort partition code
//
// ------------------------------------------------------------------
int partition(std::vector<int>& data, int start, int end)
{
	int middle = (start + end) / 2;
	std::swap(data[start], data[middle]);
	int pivotIndex = start;
	int pivotValue = data[start];
	for (int scan = start + 1; scan <= end; scan++)
	{
		if (data[scan] < pivotValue)
		{
			pivotIndex++;
			std::swap(data[scan], data[pivotIndex]);
		}
	}

	std::swap(data[pivotIndex], data[start]);

	return pivotIndex;
}

// ------------------------------------------------------------------
//
// Provided quicksort code
//
// ------------------------------------------------------------------
void quickSort(std::vector<int>& data, int start, int end)
{
	
	if (start < end)
	{
		if (data.size() <= 10 || (end - start) <= 10) {
			for (int i = start; i <= end; i++) {
				int begin = i;
				for (int j = i + 1; j <= end; j++) {
					if (data[j] < data[begin]) {
						begin = j;
					}
				}
				int temp = data[begin];
				data[begin] = data[i];
				data[i] = temp;
			}
		}
		else {
			int pivot = partition(data, start, end);
			quickSort(data, start, pivot - 1);
			quickSort(data, pivot + 1, end);
		}
	}
}
bool isWordSymmetric(const std::vector<std::string>& words, int start, int end) {
	if (start >= end) return true;
	if (words[start] == words[end]) return isWordSymmetric(words, start + 1, end - 1);
	return false;
}

long vectorSum(const std::vector<int>& data, unsigned int position) {
	if (position == data.size()) {
		return 0;
	}
	else {
		return data[position] + vectorSum(data, position + 1);
	}
}

int vectorMin(const std::vector<int>& data, unsigned int position) {
	if (position == data.size() - 1) {
		return data[position];
	}
	else {
		if (data[position] < vectorMin(data, position + 1)) {
			return data[position];
		}
		return vectorMin(data, position + 1);
	}
}