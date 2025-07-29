#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

std::vector<std::string> generateColorMap() {
    std::vector<std::string> colorMap;
    int pairNumber = 1;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorMap.push_back(
                std::to_string(pairNumber) + " | " + majorColor[i] + " | " + minorColor[j]
            );
            pairNumber++;
        }
    }
    return colorMap;
}

int printColorMap() {
    auto colorMap = generateColorMap();
    for(const auto& line : colorMap) {
        std::cout << line << "\n";
    }
    return static_cast<int>(colorMap.size());
}

void testGenerateColorMap() {
    auto colorMap = generateColorMap();
    assert(colorMap.size() == 25);
    assert(colorMap[0] == "1 | White | Blue");
    assert(colorMap[24] == "25 | Violet | Slate");
    // Add more assertions as needed
    std::cout << "All color map generation tests passed!\n";
}

void testPrintColorMap() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
}
