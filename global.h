#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace Global
{

    enum Datatypes {
        INT,
        STRING,
        BOOL, // acceptable values are "0" and "1"
    };

    int findElementIndexInVector(std::vector<std::string> thisVector, std::string element) {
        for (int i = 0; i < thisVector.size(); i++) {
            if (thisVector[i] == element) {
                return i;
            }
        }
        return -1;
    }

    class Document {
        public:
        
        std::vector<std::string> keys = {};
        std::vector<std::string> values = {};

        Document(std::vector<std::string> keys, std::vector<std::string> values) {
            this->keys = keys; this->values = values;
        }

        int findIndexOfKey(std::string key) {
            return findElementIndexInVector(keys, key);
        }

        std::string* getValue(std::string key) {
            int index = findIndexOfKey(key);
            if (index != -1) {
                return &values[index];
            }
            else {
                return nullptr;
            }
        };

        bool hasKey(std::string key) {
            if (findIndexOfKey(key) != -1) {
                return true;
            }
            return false;
        }

        void updateValue(std::string key, std::string newValue) {
            values[findIndexOfKey(key)] = newValue;
        }

        std::string toString() {
            std::string toReturn = "{";
            for (int i = 0; i < this->keys.size(); i++) {
                if (i!=0) {toReturn += ",";}
                toReturn += " " + keys.at(i) + " : " + values.at(i);
            }

            return toReturn + " }";
        }
    };

    class Database {
        public:

        std::vector<Document> documents;
        std::vector<std::string> keys;
        std::vector<int> keyTypes;

        Database(std::vector<std::string> keys, std::vector<int> keyTypes) {
            this->keys = keys; this->keyTypes = keyTypes;
        };

        int createDocument(std::vector<std::string> values = {}) { // returns the new document's index
            if (values.empty() || values.size() != keys.size()) { // no input values provided, so values has to be manually populated
                for (int i = 0; i < keys.size(); i++) {
                    values.push_back("");
                }
            }
            documents.push_back(Document(keys, values));
            return (documents.size() - 1);
        }

        int addDocument(Document doc) {
            if (doc.keys == keys) {
                documents.push_back(doc);
                return 0;
            }
            else {
                return -1;
            }
        }

        std::vector<Document> search(std::map<std::string, std::string> filters={}) { // example filters : { {"key1" : "true"},  {"key2" : "false"} }
            std::vector<Document> results = {};

            for (int i = 0; i < this->documents.size(); i++) {
                Document thisDoc = this->documents.at(i);

                if (filters.size() != 0) {
                    bool satisfiesConditions = true;
                    auto pair = filters.begin();
                    for (int i = 0; i < filters.size(); i++) {
                        if (thisDoc.hasKey(pair->first)) {
                            if (*thisDoc.getValue(pair->first) != pair->second) {
                                satisfiesConditions = false;
                                break;
                            }
                        }
                        else {
                            return {};
                        }
                        std::advance(pair, 1);
                    }
                    if (satisfiesConditions) {
                        results.push_back(thisDoc);
                    }
                }
                else {
                    results.push_back(thisDoc);
                }
            }

            return results;
        }
    };

    std::string vectorOfDocumentsToString(std::vector<Document> vectorOfDocs) {
        std::string toReturn = "";
        for (int i = 0; i < vectorOfDocs.size(); i++) {
            toReturn += vectorOfDocs[i].toString() + "\n";
        }
        return toReturn;
    }
}