#include "test.h"
#include "lab3.h"

#include <cassert>


void test_find_minmax() {
    {
        vector<double> numbers = { 1, 2, 3, 4, 5 };
        double min = 0;
        double max = 0;
        find_minmax(numbers, min, max);
        assert(min == 1);
        assert(max == 5);
    }
    {
        vector<double> numbers = { -1, -2, -3, -4, -5 };
        double min = 0;
        double max = 0;
        find_minmax(numbers, min, max);
        assert(min == -5);
        assert(max == -1);
    }
    {
        vector<double> numbers = { 0, 0, 0, 0, 0 };
        double min = 0;
        double max = 0;
        find_minmax(numbers, min, max);
        assert(min == 0);
        assert(max == 0);
    }
}


void test_make_histogram() {
    {
        vector<double> numbers = { 1, 2, 3, 4, 5 };
        size_t bin_count = 5;
        auto result = make_histogram(numbers, bin_count);
        assert(result.size() == bin_count);
        for (size_t bin : result) {
            assert(bin == 1);
        }
    }
    {
        vector<double> numbers = { 1, 1, 1, 1, 1 };
        size_t bin_count = 5;
        auto result = make_histogram(numbers, bin_count);
        assert(result.size() == bin_count);
        assert(result[0] == 5);
        for (size_t i = 1; i < bin_count; i++) {
            assert(result[i] == 0);
        }
    }
}

/*int main() {
    test_find_minmax();
    test_make_histogram();
    
    return 0;
}*/
