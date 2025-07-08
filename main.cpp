#include "global.h"

using namespace Global;

int main() {
    std::vector<std::string> values = {"1", "september 9th"};
    std::vector<std::string> keys = {"created", "due"};
    Document testDoc = Document(keys, values);
    Document testDoc2 = Document(keys, values);
    Database thisDatabase = Database(keys, {BOOL, STRING});

    std::vector<Database> system = {};

    testDoc.updateValue("created", "0");

    thisDatabase.addDocument(testDoc);
    thisDatabase.addDocument(testDoc2);

    system.push_back(thisDatabase);

    std::vector<Document> results = thisDatabase.search({{"created", "2"}});
    if (results.size() != 0) {
        std::cout << vectorOfDocumentsToString(results);
    }
    else {
        // std::cout << results << std::endl;
        std::cout << "One or more of the keys in the filters do not exist in this database, or the database is empty, or no documents match the filter" << std::endl;
    }

    return 0;
}