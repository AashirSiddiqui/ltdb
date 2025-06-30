#include <iostream>
#include <vector>
#include <string>
#include "global.h"
#include <map>

using namespace Global;

int main() {
    std::vector<std::string> values = {"1", "september 9th"};
    std::vector<std::string> keys = {"created", "due"};
    Document testDoc = Document(keys, values);

    testDoc.updateValue("created", "0");

    std::string* value = testDoc.getValue("created");
    if (value != nullptr) {
        std::cout << *value << std::endl;
    }
    else {
        std::cout << "This key does not exist in the document" << std::endl;
    }

    return 0;
}