#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n){
    vector<int> row(n, 1);

    for(int i = 0; i < m - 1; i++) {
        vector<int> aux(n, 1);

        for(int j = n - 2; j >= 0; j--){
            aux[j] = aux[j + 1] + row[j];
        }
        row = aux;
    }

    return row[0]; 
}