#include <iostream>

using namespace std;

const int SIZE = 3;

bool isReflexive(int relation[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (relation[i][i] != 1) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(int relation[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (relation[i][j] != relation[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isAsymmetric(int relation[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (relation[i][j] == 1 && relation[j][i] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(int relation[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (relation[i][j] == 1) {
                for (int k = 0; k < SIZE; k++) {
                    if (relation[j][k] == 1 && relation[i][k] != 1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int relation[SIZE][SIZE] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << "The relation is:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << relation[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Reflexive: " << (isReflexive(relation) ? "Yes" : "No") << endl;
    cout << "Symmetric: " << (isSymmetric(relation) ? "Yes" : "No") << endl;
    cout << "Asymmetric: " << (isAsymmetric(relation) ? "Yes" : "No") << endl;
    cout << "Transitive: " << (isTransitive(relation) ? "Yes" : "No") << endl;

    return 0;
}
