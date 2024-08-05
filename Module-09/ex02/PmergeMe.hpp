#pragma once

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>


#define BEFOR  "\e[0;31m"
#define AFTER  "\e[0;32m"
#define MAG "\e[0;35m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"



class PmergeMe
{

public:

    //Orthodox Canonical Form
    PmergeMe();
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    PmergeMe(const PmergeMe& other);
    
    //Vector sort functions
    static void mergeInsertionSortVector(std::vector<int> &container, int start, int end);
    static void mergeSortVector(std::vector<int> &container, int start, int mid, int end);
    static void insertionSortVector(std::vector<int> &container, int start, int end);

    //Deque sort functions
    static void mergeInsertionSortDeque(std::deque<int> &container, int start, int end);
    static void mergeSortDeque(std::deque<int> &container, int start, int mid, int end);
    static void insertionSortDeque(std::deque<int> &container, int start, int end);
    
    //Calcualte time functions
    static void runVector(std::vector<int> &container);
    static void runDeque(std::deque<int> &container);
};

// Utility functions
void print(std::vector<int> &, std::deque<int> &);
void caluclateTime(std::vector<int> &, std::deque <int> &, double &, double &);
int midPoint(int start, int end);