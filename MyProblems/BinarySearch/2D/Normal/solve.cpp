//https://leetcode.com/problems/search-a-2d-matrix/

#include<iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int tar) {
    int n = matrix.size();
    int m = matrix[0].size();

    int l = 0, r = n * m - 1;
    while (l < r){
        int mid = (l + r) >> 1;
        if (matrix[floor(mid / m)][mid % m] >= tar) r = mid;
        else l = mid + 1;
    }

    return (matrix[floor(l / m)][l % m] == tar) ? true : false;
}

int main(){
    
    return 0;
}