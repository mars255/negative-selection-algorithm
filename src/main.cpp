#include <vector> 
#include "detector.h"

int main (int argc, char **argv) {
    std::vector<std::vector<int>> self_data;
    size_t size;

        if (argc < 7) {
        std::cout << "Usage: ./detector input_file_path output_file_path threshold num_detectors lower_bound upper_bound\n";
        exit(1);
    }

    // Parse the command-line arguments
    std::string input_file_path = argv[1];
    std::string output_file_path = argv[2];
    double threshold = std::stof(argv[3]); // Convert string to float
    size_t num_detectors = std::stoull(argv[4]); // Convert string to int
    int lower_bound = std::stoi(argv[5]);
    int upper_bound = std::stoi(argv[6]);

    read_self_data (input_file_path, self_data, size);

    std::vector<std::vector<int>> detectors = generate_detectors(self_data, threshold, num_detectors, lower_bound, upper_bound);
    print_generators_to_file(detectors, output_file_path);

    return 0;
}