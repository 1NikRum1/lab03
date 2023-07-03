#include <iostream>
#include <vector>
#include <algorithm>

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

std::vector<double> input_numbers(size_t count) {
    std::vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        std::cin >> result[i];
    }
    return result;
}

void find_minmax(const std::vector<double>& numbers, double& min, double& max) {
    min = *std::min_element(numbers.begin(), numbers.end());
    max = *std::max_element(numbers.begin(), numbers.end());
}

std::vector<size_t> make_histogram(const std::vector<double>& numbers, size_t bin_count) {
    std::vector<size_t> bins(bin_count);
    double min, max;
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < numbers.size(); i++) {
        size_t bin = (size_t)((numbers[i] - min) / bin_size);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }

    return bins;
}

void show_histogram_svg(const std::vector<size_t>& bins) {
    size_t max_count = *std::max_element(bins.begin(), bins.end());
    std::vector<size_t> heights(bins.size());
    for (size_t i = 0; i < bins.size(); i++) {
        heights[i] = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
    }

    size_t max_height = *std::max_element(heights.begin(), heights.end());
    for (size_t i = max_height; i > 0; i--) {
        for (size_t j = 0; j < bins.size(); j++) {
            if (heights[j] >= i) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    size_t number_count;
    std::cout << "Enter number count: ";
    std::cin >> number_count;

    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    std::cout << "Enter bin count: ";
    std::cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);

    show_histogram_svg(bins);

    return 0;
}
