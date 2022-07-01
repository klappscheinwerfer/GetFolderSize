#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include <filesystem>

#include "../include/program_options.hpp"

int main(int argc, char* argv[]) {
    // Error log

    try {
        program_options::parse(argc, argv);
    }
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    if (argc <= 2) {
        std::cout << "Not enough arguments provided (" << argc << ")";
    }
    else {
        // Input and output
        std::string folderPath = argv[1];
        std::string outputPath = argv[2];

        // Create stream
        std::ofstream Output;
        Output.open(outputPath, std::ios_base::app);

        // Loop trough files and get file sizes
        unsigned long long totalSize = 0;
        for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(folderPath)) {
            if(!dirEntry.is_directory()) {
                //std::cout << dirEntry.file_size() << std::endl;
                totalSize += dirEntry.file_size();
            }
        }
        auto t = std::chrono::system_clock::now();
        std::time_t now = std::chrono::system_clock::to_time_t(t);
        Output << totalSize << "\t" << std::time(0) << "\t" << std::ctime(&now);

        // Close stream
        Output.close();
    }
    return 0;
}