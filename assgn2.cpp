#include <iostream>
#include <vector>

using namespace std;

bool solveLinearEquations(const vector<vector<double>>& equations, vector<double>& solution) {
    int n = equations.size();
    vector<vector<double>> mat(n, vector<double>(n + 1));

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < equations[i].size(); j++) {
            mat[i][j] = equations[i][j];
        }
    }

    
    for (int i = 0; i < n; ++i) {
        if (mat[i][i] == 0) {
            
            int idx = -1;
            for (int j = i + 1; j < n; j++) {
                if (mat[j][i] != 0) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
                return false; 
            swap(mat[i], mat[idx]);
        }
        for (int j = i + 1; j < n; ++j) {
            double factor = mat[j][i] / mat[i][i];
            for (int k = i; k <= n; ++k) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    
    solution.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = mat[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= mat[i][j] * solution[j];
        }
        solution[i] /= mat[i][i];
    }

    return true; 
}

int main() {
    int x;
    cin >> x;

    vector<vector<double>> equations(x, vector<double>(x + 1));
    for (int i = 0; i < x; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c + 1; ++j) {
            cin >> equations[i][j];
        }
    }

    vector<double> solution;
    if (solveLinearEquations(equations, solution)) {
        cout << "YES" << endl;
        cout.precision(2);
        cout << fixed;
        for (double val : solution) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
