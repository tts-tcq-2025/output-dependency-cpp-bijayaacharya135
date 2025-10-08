#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

struct ColorPair
{
    int index;
    std::string major;
    std::string minor;
};

// Generate all color pairs
std::vector<ColorPair> generateColorPairs()
{
    const char *majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char *minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<ColorPair> pairs;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int index = i * 5 + j;
            pairs.push_back({index, majorColors[i], minorColors[i]});
        }
    }
    return pairs;
}

// Format a single ColorPair line
std::string formatColorPair(const ColorPair &pair)
{
    std::ostringstream oss;

    oss << pair.index << " | " << pair.major << " | " << pair.minor;
    return oss.str();
}

// Print all color pairs
void printColorMap()
{
    auto pairs = generateColorPairs();
    for (const auto &pair : pairs)
    {
        std::cout << formatColorPair(pair) << "\n";
    }
}

void failTest(const std::string &message)
{
    throw std::runtime_error(message);
}

// TEST: Pipe alignment test using formatter output
void testPipeAlignmentOnFormattedOutput()
{
    // Use two sample pairs with intentionally different widths
    ColorPair sample1 = {0, "White", "Blue"};
    ColorPair sample2 = {10, "Violet", "Slate"};

    std::string line1 = formatColorPair(sample1);
    std::string line2 = formatColorPair(sample2);

    size_t pipe1_pos_1 = line1.find('|');
    size_t pipe2_pos_1 = line1.find('|', pipe1_pos_1 + 1);

    size_t pipe1_pos_2 = line2.find('|');
    size_t pipe2_pos_2 = line2.find('|', pipe1_pos_2 + 1);

    std::cout << "Sample line 1: " << line1 << "\n";
    std::cout << "Sample line 2: " << line2 << "\n";

    if (pipe1_pos_1 != pipe1_pos_2 || pipe2_pos_1 != pipe2_pos_2)
    {
        std::cerr << "[FAIL] Misalignment detected in formatColorPair()\n";
        std::cerr << "        Line 1: pipes at " << pipe1_pos_1 << ", " << pipe2_pos_1 << "\n";
        std::cerr << "        Line 2: pipes at " << pipe1_pos_2 << ", " << pipe2_pos_2 << "\n";
        failTest("formatColorPair() produces misaligned output");
    }
    else
    {
        std::cout << "[PASS] formatColorPair() aligns '|' characters correctly (unexpected!)\n";
    }
}

void testGenerateColorPairs()
{
    std::vector<ColorPair> pairs = generateColorPairs();

    // Test 1: Check index 1 (White, Orange) expected
    ColorPair expected1 = {1, "White", "Orange"};
    ColorPair actual1 = pairs[0];

    std::cout << "\nTesting ColorPair at index 1:\n";
    std::cout << "Expected: " << expected1.index << " | " << expected1.major << " | " << expected1.minor << "\n";
    std::cout << "Actual  : " << actual1.index << " | " << actual1.major << " | " << actual1.minor << "\n";

    if (actual1.index != expected1.index)
    {
        failTest("Numeric value mismatch");
    }
}

void testPrintColorMap()
{
    std::cout << "\nPrint color map test\n";
    printColorMap();

    std::cout << "Running unit test on formatColorPair for '|' misalignment:\n";
    try
    {
        testPipeAlignmentOnFormattedOutput();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "[ERROR] testPipeAlignmentOnFormattedOutput failed: " << ex.what() << "\n";
    }

    std::cout << "Running unit test on generateColorPairs for numeric value misalignment:\n";
    try
    {
        testGenerateColorPairs();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "[ERROR] testGenerateColorPairs failed: " << ex.what() << "\n";
    }

    std::cout << "All is well (maybe!)\n";
}
