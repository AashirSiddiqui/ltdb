#include "global.h"

using namespace Global;

int main() {
    std::vector<std::string> values = {"1", "september 9th"};
    std::vector<std::string> keys = {"created", "due"};
    Document testDoc = Document(keys, values);
    Document testDoc2 = Document(keys, values);
    Database thisDatabase = Database(keys, {BOOL, STRING});

    testDoc.updateValue("created", "0");

    thisDatabase.addDocument(testDoc);
    thisDatabase.addDocument(testDoc2);

    std::vector<Document>* results = thisDatabase.search();
    if (results != nullptr) {
        std::cout << (*results).at(0).toString() << std::endl;
    }
    else {
        // std::cout << results << std::endl;
        std::cout << "One or more of the keys in the filters do not exist in this database, or the database is empty" << std::endl;
    }

    return 0;
}