#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "src/data_processor.hpp"
int main() {
    std::ifstream input_Eruption_File;
    input_Eruption_File.open("../data/old_faithful.csv");
    std::vector<double> erupt_times;
    std::vector<int> wait_times;
    std::string line;
    if (input_Eruption_File.is_open())
    {
        std::stringstream my_string_stream;
        int pos = 0;
        bool ignore_first_line = false;
        while (getline(input_Eruption_File, line))
        {
            if (ignore_first_line) {
                pos = line.find(",");
                my_string_stream << line.substr(0, pos);
                erupt_times.push_back(std::stod(my_string_stream.str()));
                my_string_stream.str("");
                my_string_stream.clear();
                my_string_stream << line.substr(pos + 1);
                wait_times.push_back(std::stoi(my_string_stream.str()));
            }
            else {
                ignore_first_line = true;
            }
        }
    }
    else
    {
       std::cout << "Sorry, the file could not be opened." << std::endl;
    }
    std::cout << "The average eruption length is " << findAverage(erupt_times) << " minutes.\n";
    std::cout << "The average eruption wait time is " << findAverage(wait_times) << " minutes.\n";

    std::cout << "Writing a new CSV file called faithful_updated.csv.\n" << std::endl;
    std::ofstream outputFile("..data/faithful_updated.csv");
    int i = 0;
    while (std::getline(input_Eruption_File, line)) {
        outputFile << line << ", " << bool_print(wait_times[i]) << std::endl;
        i++;
    }
    outputFile.close();

    input_Eruption_File.close();
    return 0;
}