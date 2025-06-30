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

        void updateValue(std::string key, std::string newValue) {
            values[findIndexOfKey(key)] = newValue;
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
            else {
                documents.push_back(Document(keys, values));
                return (documents.size() - 1);
            }
        }
    };
}