#include<bits/stdc++.h>
using namespace std;

void adjlist(int u, int v, unordered_map<int, list<int>>& mp) {
    mp[u].push_back(v);
}

void showadjmatrix(vector<vector<int>>& mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose(vector<vector<int>>& mat, vector<vector<int>>& nums, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) {
                nums[j][i] = 1;
            }
        }
    }
    mat = nums;
    cout << "Matrix after transpose:" << endl;
    showadjmatrix(mat, n);
}

void showlist(unordered_map<int, list<int>>& mp, int n) {
    for(int i = 0; i < n; i++) {
        cout << i << ":";
        for(auto nbr : mp[i]) {
            cout << nbr << " ";
        }
        cout << endl;
    }
}

void transposelist(unordered_map<int, list<int>>& mp, int n) {
    unordered_map<int, list<int>> up;
    for(int i = 0; i < n; i++) {
        for(auto k : mp[i]) {
            up[k].push_back(i);
        }
    }
    mp = up;
    cout << "List after transpose:" << endl;
    showlist(mp, n);
}

int main() {
    unordered_map<int, list<int>> mp;
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> nums(n, vector<int>(n, 0));
    
    for(int i = 0; i < e; i++) {
        int u, v;
        cout << "Enter the node: ";
        cin >> u;
        cout << "Enter the node that has an edge from u: ";
        cin >> v;
        
        if(u >= n || v >= n || u < 0 || v < 0) {
            cout << "Invalid node values entered." << endl;
        } else {
            mat[u][v] = 1;
            adjlist(u, v, mp);
        }
    }
    
    cout << "Adjacency matrix before transpose:" << endl;
    showadjmatrix(mat, n);
    
    transpose(mat, nums, n);
    
    cout << "Graph implementation using adjacency list:" << endl;
    cout << "Adjacency list:" << endl;
    showlist(mp, n);
    
    transposelist(mp, n);
    
    return 0;
}
