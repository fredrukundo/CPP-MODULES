#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other) {
        return *this; 
    }
    return *this;
};
PmergeMe::PmergeMe(const PmergeMe& other){(void)(other);
};

/***************************************Vector sorting part***************************************/

/*
    desc:
     ``this function combines INSERTION sort and MERGE sort, if subarray is less than 10,
    it calls INSERTION sort for efficience otherwise it splits the array in half, sorts each
    half recursively and then merges them ``


*/
void PmergeMe::mergeInsertionSortVector(std::vector<int> &container, int start, int end)
{
    int newEnd;
    if (start < end)
    {
        if ((end - start) < 10)
            insertionSortVector(container, start, end);
        else
        {
            newEnd = start + (end - start) / 2;//calc midpoint (newEnd) of the subarray
            mergeInsertionSortVector(container,  start, newEnd);//sort left half subarray (recursively)
            mergeInsertionSortVector(container, newEnd + 1, end);//sort right half subarray (recursively)
            mergeSortVector(container, start, newEnd, end);//merge two sorted halves using "mergeSortVector"
        }
    }
};

/*
    desc:
    "this function merges two sorted subarrays into a single sorted subarray"

    - start (beginning index of 1st subarray)
    - mid (ending index of 1st subarray), which is one less the beginning of 2nd subarray
    - end (ending index of 2nd subarray)

    * creates temp arrays (left and right), copies elements from the two subarrays into temp arrays
    * merge temps arrays (left and right) back into orginal array 
     (compares elements from left, right array and places the smaller one into container)
    * finally copy the remaining elements of temp arrays

*/

void PmergeMe::mergeSortVector(std::vector<int> &container, int start, int mid, int end)
{
    int i, j , k;

    std::vector<int> left(mid - start + 1);
    std::vector<int> right(end - mid);

    for(i = 0; i < (mid - start + 1); ++i)
        left[i] = container[start + i];
    for(j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        container[k++] =  left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
};

/*
    desc:
        - this function sorts the subarray from start index to end using INSERTION sort algo

*/
void PmergeMe::insertionSortVector(std::vector<int> &container, int start, int end)
{
    for(int index = start + 1; index <= end; index++)
    {
        int hold = container[index];
        int j = index - 1;
        for(; j >= start && container[j] > hold; --j)
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
};

/*
    desc:
        the entry point for sorting the entire vector
*/
void PmergeMe::runVector(std::vector<int> &container)
{
    mergeInsertionSortVector(container, 0, container.size() - 1);
};

void PmergeMe::runDeque(std::deque<int> &container)
{
    mergeInsertionSortDeque(container, 0, container.size() - 1);
};

/***************************************Deque sorting part***************************************/
void PmergeMe::mergeInsertionSortDeque(std::deque<int> &container, int start, int end)
{
    int newEnd;
    if (start < end)
    {
        if ((end - start) < 10)
            insertionSortDeque(container, start, end);
        else
        {
            newEnd = start + (end - start) / 2;
            mergeInsertionSortDeque(container,  start, newEnd);
            mergeInsertionSortDeque(container, newEnd + 1, end);
            mergeSortDeque(container, start, newEnd, end);
        }
    }
};

void PmergeMe::mergeSortDeque(std::deque<int> &container, int start, int mid, int end)
{
    int i, j , k;

    std::deque<int> left(mid - start + 1);
    std::deque<int> right(end - mid);

    for(i = 0; i < (mid - start + 1); ++i)
        left[i] = container[start + i];
    for(j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        container[k++] =  left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
};

void PmergeMe::insertionSortDeque(std::deque<int> &container, int start, int end)
{
    for(int index = start + 1; index <= end; index++)
    {
        int hold = container[index];
        int j = index - 1;
        for(; j >= start && container[j] > hold; --j)
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
};

/**************************************Utility functions part***************************************/
void caluclateTime(std::vector<int> &Vcontainer, std::deque<int> &Dcontainer,double &vecTime, double &deqTime)
{
    std::clock_t start = std::clock();
    PmergeMe::runVector(Vcontainer);
    std::clock_t end = std::clock();
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
    vecTime = elapsed;
    start = std::clock();
    PmergeMe::runDeque(Dcontainer);
    end = std::clock();
    elapsed = static_cast<double> (end - start) / (CLOCKS_PER_SEC / 1000000.0);
    deqTime = elapsed;
    
}

void print(std::vector<int> &Vec, std::deque<int> &Deq)
{

    static int i = 0;

    if (!i)
        std::cout << MAG << "Vector "  << "before : " << BEFOR;
    else
        std::cout << MAG << "Vector "<< "after : " << AFTER; 

    typedef std::vector<int>::const_iterator Viterator;
    for (Viterator Vit = Vec.begin(); Vit != Vec.end(); ++Vit)
		std::cout << *Vit << " ";
    std::cout << std::endl;

    if (!i)
        std::cout << MAG << "Deque " << " before : " << BEFOR ;
    else
        std::cout << MAG << "Deque "  << " after : " << AFTER;
    typedef std::deque<int>::const_iterator Diterator;
    for (Diterator Dit = Deq.begin(); Dit != Deq.end(); ++Dit)
		std::cout << *Dit << " ";
    std::cout << std::endl;
    i++;
}

int midPoint(int start, int end)
{
    return(start + (end - start) / 2);
}