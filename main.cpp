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
//method for addition just add the corresponding x,y coordinated values in each matrix
void add(int size, int A[100][100], int B[100][100]){
    cout << "\n The sum of the two matrices: " << endl;
        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                cout << A[x][y] + B[x][y] << " ";
            }
            cout << endl;
        }
}
//method for multiplication uses 3 for loops to multiply and odd the corresponding row and column of the second matrix
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
//same as add but subtracts instead
void subtract(int size, int A[100][100], int B[100][100]){
    cout << "\n The difference of the two matrices: " << endl;
        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                //change done in this line
                cout << A[x][y] - B[x][y] << " ";
            }
            cout << endl;
        }
}

//prints a matrix in a organized format
void print_matrix(int size, int A[100][100]){
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            cout << A[x][y] << " ";
        }
        cout << endl;
    }
}

void change_element(int row, int column, int A[100][100],int size, int new_val){
    if(row > 0 && row < size && column > 0 && column < size){
        A[row][column] = new_val;
        cout << "Element at point (" << row << ", " << column << ") updated to " << new_val << endl;
        print_matrix(size, A);
    }
    else {
        cout << "Invalid Input" <<endl;
    }
}

void max(int size, int A[100][100]){
    int max = A[0][0]; // Initialize max_value to smallest possible integer

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (A[x][y] > max) {
                max = A[x][y];
            }
        }
    }
    cout << "The maximum value in the matrix is: " << max << endl;
}

void transpose(int size, int A[100][100]){
    cout << "Matrix A transposed: " << endl;
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            cout << A[y][x] << " ";
        }
        cout << endl;
    }
}
int main(){
    //define matrices
    int A[100][100];
    int B[100][100];
    //file name
    string file;
    cout << "\nType the name of the file\n" << endl;
    //get the file name for me it was input.txt
    cin >> file;
    //read the file and get A and B and and get the size of each matrix which is size
    int size = readin(file, A, B);
    cout <<"Matrix A:" << endl;
    //print A
    print_matrix(size, A);

    cout <<"Matrix B" << endl;
    //print B
    print_matrix(size, B);

    //complete the operations; no need to print because its already done in the functions
    add(size, A, B);
    subtract(size, A, B);
    multiply(size, A, B);

    int row;
    int column; 
    int new_val;
    cout << "Enter the row, column, and updated value of matrix A: ";
    cin >> row >> column >> new_val;
    change_element(row, column, A, size, new_val);
    max(size, A);
    transpose(size, A);

}