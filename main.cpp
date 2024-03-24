#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readin(string file, int A[100][100], int B[100][100]){
    ifstream infile(file);
    int size;
    infile >> size;

    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            infile >> A[x][y];
        }
    }

    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            infile >> B[x][y];
        }
    }

    infile.close();
    return size;
}

void add(int size, int A[100][100], int B[100][100]){
    cout << "\n The sum of the two matrices: " << endl;
        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                cout << A[x][y] + B[x][y] << " ";
            }
            cout << endl;
        }
}

void multiply(int size, int A[100][100], int B[100][100]){
        int temp[100][100];
    cout << "\nThe product of the two matrices is: "<< endl;

        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                temp[x][y] = 0;
                for(int z = 0; z < size; z++){
                    temp[x][y] += A[x][z] * B[z][y];
                }
                cout << temp[x][y] << " ";
            }
            cout << endl;
        }
}

void subtract(int size, int A[100][100], int B[100][100]){
    cout << "\n The difference of the two matrices: " << endl;
        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                cout << A[x][y] - B[x][y] << " ";
            }
            cout << endl;
        }
}

void print_matrix(int size, int A[100][100]){
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            cout << A[x][y] << " ";
        }
        cout << endl;
    }
}

int main(){
    int A[100][100];
    int B[100][100];
    string file;
    cout << "\nType the name of the file\n" << endl;
    cin >> file;
    int size = readin(file, A, B);
    cout <<"Matrix A:" << endl;
    print_matrix(size, A);

    cout <<"Matrix B" << endl;
    print_matrix(size, B);

    add(size, A, B);
    subtract(size, A, B);
    multiply(size, A, B);

}