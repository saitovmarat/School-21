#include <iostream>
#include <math.h>

int** resultMatrix(int n);
void printMatrix(int** matrix, int n);

int main(){
    int n = 0;
    std::cin >> n;
    printMatrix(resultMatrix(n), n);
}

int** resultMatrix(int n){
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    int num = 0;

    int startingNum = 0;
    int endingNum = 0;
    while(num != pow(n, 2)){
        for(int rotate = 0; rotate < 4; rotate++){
            switch (rotate)
            {
                case 0:{
                    for(int i = startingNum; i < n-endingNum; i++)
                        matrix[startingNum][i] = ++num;
                    startingNum++;
                    break;
                }
                case 1:{
                    for(int i = startingNum; i < n-endingNum; i++)
                        matrix[i][n-1-endingNum] = ++num;
                    break;
                }
                case 2:{
                    for(int i = n-1-startingNum; i > endingNum-1; i--)
                        matrix[n-1-endingNum][i] = ++num;   
                    endingNum++;
                    break;
                }
                case 3:{
                    for(int i = n-1-startingNum; i > endingNum-1; i--)
                        matrix[i][endingNum-1] = ++num;
                    break;
                }
            }
        }
    }
    return matrix;
}
void printMatrix(int** matrix, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
