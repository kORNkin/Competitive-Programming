#include <iostream>

int main() {
    int n; std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cout << "z";
    } std::cout << "\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == n - j - 1) std::cout << "z";
            else std::cout << " ";   
        } std::cout << "\n";
    }
    
    for(int i = 0; i < n; i++){
        std::cout << "z";
    }
}