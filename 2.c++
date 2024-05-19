#include <iostream>
using namespace std;

struct Element {
    int i, j, x;
};

struct Sparse {
    int m, n, num;
    Element* ele;

    Sparse(int m = 0, int n = 0, int num = 0) : m(m), n(n), num(num) {
        ele = new Element[num];
    }

    ~Sparse() {
        delete[] ele;
    }

    void create() {
        cout << "Enter the dimension of the matrix: ";
        cin >> m >> n;
        cout << "Number of non-zero elements: ";
        cin >> num;
        ele = new Element[num];
        cout << "Enter the non-zero elements: ";
        for (int i = 0; i < num; i++) {
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
        }
    }

    void display() {
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (k < num && i == ele[k].i && j == ele[k].j) {
                    cout << ele[k++].x << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    Sparse* add(Sparse* s2) {
        if (m != s2->m || n != s2->n) {
            cout << "Addition cannot happen!!" << endl;
            return nullptr;
        }

        Sparse* s = new Sparse(m, n, num + s2->num);
        int i = 0, j = 0, k = 0;

        while (i < num && j < s2->num) {
            if (ele[i].i < s2->ele[j].i || (ele[i].i == s2->ele[j].i && ele[i].j < s2->ele[j].j)) {
                s->ele[k++] = ele[i++];
            } else if (ele[i].i > s2->ele[j].i || (ele[i].i == s2->ele[j].i && ele[i].j > s2->ele[j].j)) {
                s->ele[k++] = s2->ele[j++];
            } else {
                s->ele[k] = ele[i];
                s->ele[k++].x += s2->ele[j++].x;
                i++;
            }
        }

        while (i < num) {
            s->ele[k++] = ele[i++];
        }

        while (j < s2->num) {
            s->ele[k++] = s2->ele[j++];
        }

        s->num = k;
        return s;
    }
};

int main() {
    Sparse s1, s2, *s3;

    s1.create();
    s1.display();
    s2.create();
    s2.display();

    s3 = s1.add(&s2);
    if (s3 != nullptr) {
        cout << endl;
        s3->display();
    }

    delete s3;
    return 0;
}
