#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "src/data_processor.hpp"
int main() {
    std::ifstream input_Eruption_File;
    input_Eruption_File.open("../old_faithful_part1/data/old_faithful.csv");
    std::vector<double> erupt_times;
    std::vector<float> erupt_log;
    std::vector<int> wait_times;
    std::string line;
    if (!input_Eruption_File.is_open())
    {
        std::cerr << "Sorry, the file could not be opened." << std::endl;
    }
    else
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
                erupt_log.push_back(std::stof(my_string_stream.str()));
                my_string_stream.str("");
                my_string_stream.clear();
                my_string_stream << line.substr(pos + 1);
                wait_times.push_back(std::stoi(my_string_stream.str()));
                my_string_stream.str("");
                my_string_stream.clear();
            }
            else {
                ignore_first_line = true;
            }
        }

        std::cout << "The average eruption length is " << findAverage(erupt_times) << " minutes.\n";
        std::cout << "The average eruption wait time is " << findAverage(wait_times) << " minutes.\n";

        std::cout << "Writing a new CSV file called faithful_updated.csv.\n" << std::endl;
        std::ofstream outputFile;
        outputFile.open("../old_faithful_part1/data/faithful_updated.csv");
        if (!outputFile.is_open()) {
            std::cerr << "Sorry, the file could not be written too." << std::endl;
        } else {
            int i = 0;
            bool gotFirstLine = false;
            for (int j = 0; j < erupt_times.size(); j++) {
                if (!gotFirstLine) {
                    gotFirstLine = true;
                    outputFile << "eruptions" << "," << "waiting" << "," << "Short Wait Time" << std::endl;
                } else {
                    outputFile << std::to_string(erupt_log[i]) << "," << std::to_string(wait_times[i]) << "," << bool_print(wait_times[i]) << std::endl;
                    i++;
                }
            }
            outputFile.close();
        }
        input_Eruption_File.close();
    }
    return 0;
}