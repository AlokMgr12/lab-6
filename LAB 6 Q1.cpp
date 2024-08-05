#include <stdio.h>
#include <stdbool.h>

bool isReflexive(int relation[][2], int n, int set[], int setSize) {
    for (int i = 0; i < setSize; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (relation[j][0] == set[i] && relation[j][1] == set[i]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool isSymmetric(int relation[][2], int n) {
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (relation[i][0] == relation[j][1] && relation[i][1] == relation[j][0]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool isAsymmetric(int relation[][2], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relation[i][0] == relation[j][1] && relation[i][1] == relation[j][0]) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(int relation[][2], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relation[i][1] == relation[j][0]) {
                bool found = false;
                for (int k = 0; k < n; k++) {
                    if (relation[i][0] == relation[k][0] && relation[j][1] == relation[k][1]) {
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }
        }
    }
    return true;
}

int main() {
    int set[] = {1, 2, 3};
    int setSize = sizeof(set) / sizeof(set[0]);

    int relation[][2] = {{1, 1}, {2, 2}, {3, 3}, {1, 2}, {2, 1}, {2, 3}, {3, 2}};
    int n = sizeof(relation) / sizeof(relation[0]);

    if (isReflexive(relation, n, set, setSize))
        printf("The relation is Reflexive\n");
    else
        printf("The relation is not Reflexive\n");

    if (isSymmetric(relation, n))
        printf("The relation is Symmetric\n");
    else
        printf("The relation is not Symmetric\n");

    if (isAsymmetric(relation, n))
        printf("The relation is Asymmetric\n");
    else
        printf("The relation is not Asymmetric\n");

    if (isTransitive(relation, n))
        printf("The relation is Transitive\n");
    else
        printf("The relation is not Transitive\n");

    return 0;
}

