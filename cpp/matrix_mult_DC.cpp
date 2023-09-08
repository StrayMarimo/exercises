/*
 <----------------------------------------------------------------------->
 This program accepts performs matrix multiplication of 2 nxn matrices
 This is a simple divide and conquer algorithm that performs:
    8 multiplications of ⌈n/2⌉ * ⌈n/2⌉ submatrices and
    4 additions of ⌈n/2⌉ * ⌈n/2⌉ submatrices
<------------------------------------------------------------------------>
 */

#include <iostream>
#include <vector>

using namespace std;

// <------------------ function prototypes ------------------------------>
void inputMatrix(vector<vector<int>> &A, int n, bool isPower2);
void displayMatrix(vector<vector<int>> &A, bool isPower2);
void sumMatrix(vector<vector<int>> A, vector<vector<int>> B,
               vector<vector<int>> &C, int rowC, int colC);
vector<vector<int>> SMMR(vector<vector<int>> A, vector<vector<int>> B,
                         int rowA, int colA, int rowB, int colB, int n);
// <--------------------------------------------------------------------->



// <------------------------- Driver ------------------------------------>
int main(){
    
    // declaration
    int n;
    bool isPower2 = 1;
    vector<vector<int>> A, B, C;
    cout << "Enter n: ";
    // input dimension of square matrix
    cin >> n;
    
    /*
     * if n is not divisible by 2, create an n+1 by n+1 matrix.
     * Since algo only works if n is divisible by 2,
     * adding 1 to n will make it divisible by 2.
     * then fill the extra cells with zeroes later on.
     */
    if (n % 2 != 0 && n > 2) {
        n++;
        isPower2 = 0;
    }
    
    // input matrices to be multiplied
    inputMatrix(A, n, isPower2);
    inputMatrix(B, n, isPower2);

    // call the recursive function and store resultant matrix to C
    C = SMMR(A, B, 0, 0, 0, 0, n);
    
    // display resultant matrix
    // (without filled zeroes if n is not divisible by 2)
    displayMatrix(C, isPower2);
    
    return 0;
}

// <------------------ function definitions ------------------------------>


/*
 *  function that partitions nxn matrix into n/2 by n/2 matrix if n != 1
 *  if n = 1, then perform a scalar multiplication
 *  overall, this function is called 8^⌈n/2⌉ times
 *  @params:
 *   A - 2d vector input matrix
 *   B - 2d vector input matrix
 *   rowA and colA - integers indicating indices of matrix A
 *           to be multiplied when base case is reached
 *   rowB and colB - integers indicating indices of matrix B
 *           to be multiplied when base case is reached
 */

vector<vector<int>> SMMR(vector<vector<int>> A, vector<vector<int>> B,
                         int rowA, int colA, int rowB, int colB, int n) {
    
    vector<vector<int>> C(n,vector<int> (n,0));

    if (n == 1) {
        C[0][0] = A[rowA][colA] * B[rowB][colB];
    } else { // partition A, B, and C
        int newSize = n / 2;
        
        // C[0][0] = (A[0][0] * B[0][0]) + A[0][1] * B[1][0]
        sumMatrix(SMMR(A, B, rowA, colA, rowB, colB, newSize),
                  SMMR(A, B, rowA, colA + newSize, rowB + newSize,
                       colB, newSize),C, 0, 0);
        
        // C[0][1] = (A[0][0] * B[0][1]) + A[0][1] * B[1][1]
        sumMatrix(SMMR(A, B, rowA, colA, rowB, colB + newSize, newSize),
                  SMMR(A, B, rowA, colA + newSize, rowB + newSize,
                       colB + newSize, newSize), C, 0, newSize);
        
        // C[1][0] = (A[1][0] * B[0][0]) + A[1][1] * B[0][1]
        sumMatrix(SMMR(A, B, rowA + newSize, colA, rowB, colB, newSize),
                  SMMR(A, B, rowA + newSize, colA + newSize, rowB + newSize,
                       colB, newSize),C, newSize, 0);
        
        // C[1][1] = (A[1][0] * B[0][1]) + A[1][1] * B[1][1]
        sumMatrix(SMMR(A, B, rowA + newSize, colA, rowB, colB + newSize, newSize),
                  SMMR(A, B, rowA + newSize, colA + newSize, rowB + newSize,
                       colB + newSize, newSize), C, newSize, newSize);
    }
    return C;
}


/*
 * function to input a matrix
 * @params:
 *   A - 2d vector passed by reference
 *   isPower2 - boolean that indicates if n is divisible by 2
 */

void inputMatrix(vector<vector<int>> &A, int n, bool isPower2) {
    
    cout << "Enter Matrix: \n";
    
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            // if isPower2 is false, fill the last column and row with zeroes
            int num = 0;
            if ((!isPower2 && j < 3 && i < 3) || isPower2)
                cin >> num;
            temp.push_back(num);
        }
        A.push_back(temp);
    }
}


/*
 * function to display a matrix
 * @params:
 *   A - 2d vector passed by reference
 *   isPower2 - boolean that indicates if n is divisible by 2
 */

void displayMatrix(vector<vector<int>> &A, bool isPower2) {
    int n = isPower2? A.size() : A.size() - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 * function to add the products of submatrices
 * overall, this function is called 4^⌈n/2⌉ times
 * @params:
 *   A - 2d vector input matrix
 *   B - 2d vector input matrix
 *   C - 2d vector reaultant matrix passed by reference
 *   rowC and colC - indices to indicate where
 *      to store the sum in resultant matrix
 */

void sumMatrix(vector<vector<int>> A, vector<vector<int>> B,
    vector<vector<int>> &C, int rowC, int colC) {
    
    int n = A[0].size();
    // this nested loop iterates ⌈n/2⌉ times
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i + rowC][j+colC] = A[i][j] + B[i][j];
        }
    }

}

