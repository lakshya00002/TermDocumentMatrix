#include <iostream>
#include <vector>

using namespace std;

class TermDocumentMatrix {
public:
    TermDocumentMatrix(int numTerm, int numDoc) : numTerm(numTerm), numDoc(numDoc) {
        matrix.resize(numTerm, vector<int>(numDoc, 0));
    }

    void updateTermFrequency(int term, int doc, int val) {
        if (term < numTerm && doc < numDoc) {
            matrix[term][doc] = val;
        } else {
            cout << "Please enter valid index of document or term" << endl;
        }
    }

    int getTermFrequency(int term, int doc) {
        if (term < numTerm && doc < numDoc) {
            return matrix[term][doc];
        } else {
            cout << "Please enter valid index of document or term" << endl;
            return -1;
        }
    }

private:
    vector<vector<int>> matrix;
    int numTerm;
    int numDoc;
};

int main() {
    int numTerm, numDoc, choice, term, doc, val;

    cout << "Enter the number of terms: ";
    cin >> numTerm;
    cout << "Enter the number of documents: ";
    cin >> numDoc;

    TermDocumentMatrix matrix(numTerm, numDoc);

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Update Term Frequency" << endl;
        cout << "2. Get Term Frequency" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter term index: ";
                cin >> term;
                cout << "Enter document index: ";
                cin >> doc;
                cout << "Enter value: ";
                cin >> val;
                matrix.updateTermFrequency(term, doc, val);
                break;
            case 2:
                cout << "Enter term index: ";
                cin >> term;
                cout << "Enter document index: ";
                cin >> doc;
                cout << "Term frequency: " << matrix.getTermFrequency(term, doc) << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
