#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct GameSettings
{
    int iterations;
    int width;
    int height;
    int numTeams;
    int teamCapacity; // Single capacity for all teams
};

GameSettings readGameSettings(const std::string &filename)
{
    std::ifstream file(filename);
    GameSettings settings;

    if (file.is_open())
    {
        std::string line;

        // Read Iterations
        if (std::getline(file, line))
        {
            std::stringstream ss(line);
            ss >> settings.iterations;
        }

        // Read Width and Height
        if (std::getline(file, line))
        {
            std::stringstream ss(line);
            ss >> settings.width >> settings.height;
        }

        // Read Number of Teams
        if (std::getline(file, line))
        {
            std::stringstream ss(line);
            ss >> settings.numTeams;
        }

        // Read Ship Capacity (Single capacity for all teams)
        if (std::getline(file, line))
        {
            std::stringstream ss(line);
            ss >> settings.teamCapacity;
        }

        file.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
    return settings;
}

int main()
{
    std::string filename = "/Users/testing/Documents/OOPDS/warship_simulation/file.txt"; // Replace with your filename
    GameSettings settings = readGameSettings(filename);

    // Display the read settings
    std::cout << "Iterations: " << settings.iterations << std::endl;
    std::cout << "Width: " << settings.width << std::endl;
    std::cout << "Height: " << settings.height << std::endl;
    std::cout << "Number of Teams: " << settings.numTeams << std::endl;
    std::cout << "Team Capacities: " << settings.teamCapacity << std::endl;

    return 0;
}