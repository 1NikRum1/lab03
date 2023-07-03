﻿#include <iostream>
#include <fstream>
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
    const auto IMAGE_WIDTH = 400;
    const auto MAX_HEIGHT = 300.0;
    const auto BIN_WIDTH = IMAGE_WIDTH / bins.size();
    const auto TEXT_HEIGHT = 20;
    const auto TEXT_BASELINE = TEXT_HEIGHT;
    const std::vector<std::string> colors = { "#000", "#f00", "#0f0", "#00f", "#ff0", "#f0f", "#0ff" };

    size_t max_count = *std::max_element(bins.begin(), bins.end());
    double scaling_factor = static_cast<double>(MAX_HEIGHT - TEXT_HEIGHT) / max_count;

    std::ofstream svg_file("histogram.svg");
    svg_file << "<?xml version='1.0' encoding='UTF-8'?>\n";
    svg_file << "<svg ";
    svg_file << "width='" << IMAGE_WIDTH << "' ";
    svg_file << "height='" << MAX_HEIGHT << "' ";
    svg_file << "viewBox='0 0 " << IMAGE_WIDTH << " " << MAX_HEIGHT << "' ";
    svg_file << "xmlns='http://www.w3.org/2000/svg'>\n";

    for (size_t i = 0; i < bins.size(); i++) {
        double height = bins[i] * scaling_factor;
        svg_file << "<rect x='" << i * BIN_WIDTH << "' y='" << MAX_HEIGHT - height << "' width='" << BIN_WIDTH << "' height='" << height << "' fill='" << colors[i % colors.size()] << "' />\n";
        svg_file << "<text x='" << i * BIN_WIDTH + BIN_WIDTH / 2 << "' y='" << MAX_HEIGHT - height - TEXT_BASELINE / 2 << "'>" << bins[i] << "</text>\n";
    }

    svg_file << "</svg>\n";
    svg_file.close();
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
