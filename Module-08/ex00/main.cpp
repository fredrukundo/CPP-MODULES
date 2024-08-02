#include "easyfind.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "One argument required" << std::endl;
        return (1);
    }
    
    int     arr[] = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int>    vec( arr, arr + sizeof( arr) / sizeof(int));
    std::list<int>    list( arr, arr + sizeof( arr) / sizeof(int));

    easyfind( vec, std::atoi( av[1]));
    easyfind(list, std::atoi(av[1]));

    return 0;

}