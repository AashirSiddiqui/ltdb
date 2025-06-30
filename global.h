namespace Global
{

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

        std::string* getValue(std::string key) {
            int index = findElementIndexInVector(keys, key);
            if (index != -1) {
                return &values[index];
            }
            else {
                return nullptr;
            }
        };
    };

    class Database {
        public:

        std::vector<Document> documents;
        std::vector<std::string> keys;

        Database(std::vector<std::string> keys);

        int createDocument(std::vector<std::string> values = {}) { // returns the new document's index
            if (values.empty()) { // no input values provided, so values has to be manually populated
            }
            else {
                documents.push_back(Document(keys, values));
                return (documents.size() - 1);
            }
        }
    };
}