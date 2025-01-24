#ifndef DETECTOR_H
#define DETECTOR_H

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

// Calculates the Euclidean distance between the elements of two vectors
template <typename T>
double euclidean_distance(const std::vector<T>& vec1, const std::vector<T>& vec2);

// Generates a valid detector
template <typename T>
std::vector<T> generate_valid_detector(const std::vector<std::vector<T>>& self_data, size_t size, T lower_bound, T upper_bound, double threshold);

// Generates multiple detectors
template <typename T>
std::vector<std::vector<T>> generate_detectors(const std::vector<std::vector<T>>& self_data, double threshold, size_t num_generators, T lower_bound, T upper_bound);

// Generates a random number between bounds
template <typename T>
T generate_random(T lower, T upper);

// Generates a random detector
template <typename T>
std::vector<T> generate_random_detector(size_t size, T lower_bound, T upper_bound);

// Checks if the detector is valid
template <typename T>
bool check_detector(const std::vector<std::vector<T>>& self_data, const std::vector<T>& detector, double threshold);

template <typename T>
int print_generators_to_file(const std::vector<std::vector<T>>& generators, const std::string& file_path);

#include "detector.tpp"

#endif // DETECTOR_H

