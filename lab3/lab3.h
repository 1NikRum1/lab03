#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> input_numbers(size_t count);
void find_minmax(const std::vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count);
std::vector<size_t> make_histogram(const std::vector<double>& numbers, size_t bin_count);

// SVG
void show_histogram_svg(const vector<size_t>& bins);