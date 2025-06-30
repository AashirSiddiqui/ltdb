#include "global.h"
#include <string>
#include <vector>

using namespace Global;

int findElementIndexInVector(std::vector<std::string> thisVector, std::string element) {
    for (int i = 0; i < thisVector.size(); i++) {
        if (thisVector[i] == element) {
            return i;
        }
    }
    return -1;
}

class Globals::Document {
    public:
    
    std::vector<std::string> keys = {};
    std::vector<std::string> values = {};

    std::string getValue(std::string key) {
        int index = findElementIndexInVector(keys, key);
        if (index != -1) {
            return values[findElementIndexInVector(keys, key)];
        }
        else {
            return NULL;
        }
    };
};