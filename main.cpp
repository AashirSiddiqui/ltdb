#include <iostream>
#include <vector>
#include <string>
#include "global.h"

using namespace Global;

int findElementIndexInVector(std::vector<std::string> thisVector, std::string element) {
    for (int i = 0; i < thisVector.size(); i++) {
        if (thisVector[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    Globals::Document testDoc = Globals::Document();
    testDoc.keys = {"created", "due"};
    testDoc.values = {"true", "september 9th"};

    std::cout << testDoc.getValue("created") << std::endl;

    return 1;
}