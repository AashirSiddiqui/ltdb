#include <iostream>
#include <vector>
#include <string>
#include "global.h"
#include <map>

using namespace Global;

int main() {
    Document testDoc = Document();
    testDoc.keys = {"created", "due"};
    testDoc.values = {"true", "september 9th"};

    std::cout << testDoc.getValue("created") << std::endl;

    return 0;
}