#include <iostream>
using namespace std;

int main()
{
    // initialize variables
    int dimension = 0;
    int x_coordinate = 0;
    int y_coordinate = 0;
    bool is_two_side_passable = false; 
    
    // get the size of matrix
    cin>>dimension;
    
    // initialize 2d input matrix and 2d resultant matrix 
    //with its dimensions depending on the inputted size
    int input_matrix[dimension][dimension];
    int solution_matrix[dimension][dimension];
    
    // iterate through every column of every row of the matrix
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j <dimension; j++)
        {
            cin>>input_matrix[i][j]; // input binary value for every cell in the matrix
            solution_matrix[i][j] = 0; // initialize every cell in resultant matrix to 0
        }
    // display no solution path and end program if the first cell is an obstacle
    if (input_matrix[0][0] == 0)
    {
        cout<<"no solution path"; 
        return 0;
    }
    
    // set is_two_side_passable variable to true if both adjacent right 
    // and adjacent down of the first cell is not an obstacle
    if (input_matrix [0][1] == 1 && input_matrix [1][0] == 1)
        is_two_side_passable = true;
        
    // repeat block of code until both x and y coordinates 
    // reaches the indexes of the last cell of the matrix
    while (x_coordinate < dimension - 1 || y_coordinate < dimension - 1)
    {
        // move right if next cell right is not an obstacle
        if (input_matrix[x_coordinate][y_coordinate+1] == 1)
            y_coordinate++;
        // otherwise, move down if next cell down is not an obstacle
        else if (input_matrix[x_coordinate+1][y_coordinate] == 1)
            x_coordinate++;
        // otherwise, go back to previous cell by doing the following:
        else
        {
            // if last cell visited was from the adjacent left, 
            if(solution_matrix[x_coordinate][y_coordinate -1] == 1)
            {
                input_matrix[x_coordinate][y_coordinate] = 0;     // set the current cell as an obstacle,
                solution_matrix[x_coordinate][y_coordinate] = 0; // delete the current cell from the solution path,
                y_coordinate--;                                 // and go left
            }
            // otherwise, if last cell visited was from the adjacent up, 
            else if(solution_matrix[x_coordinate-1][y_coordinate] == 1)
            {
                input_matrix[x_coordinate][y_coordinate] = 0;     // set the current cell as an obstacle,
                solution_matrix[x_coordinate][y_coordinate] = 0; // delete the current cell from the solution path,
                x_coordinate--;                                 // and go up 
            }
            // do the following code if the first cell will be reached by going back to a previous cell
            // or if the first cell is already reached, 
             if ((x_coordinate -1 == 0 && y_coordinate == 0)
             || (x_coordinate == 0 && y_coordinate - 1 == 0)
             || (x_coordinate == 0 && y_coordinate == 0))
             {
                 // display no solution path and end program if the 
                 // other side adjacent to first cell is an obstacle
                 if (is_two_side_passable == false) 
                 {
                     cout<<"no solution path";
                     return 0;
                 }
                 // otherwise, go to the other side of the first cell by doing the following:
                 else
                 {
                     // if the adjacent right of the first cell is the one passable, 
                     if (x_coordinate != 0)
                     {
                         input_matrix[1][0] = 0;     // set the adjacent down of the first cell as an obstacle
                         solution_matrix[1][0] = 0; // delete the adjacent down of the first cell from the solution path
                         x_coordinate = 0;         // and go back to first cell 
                     }
                     // otherwise, then the adjacent down of the first cell is the one passable
                     else
                     {
                         input_matrix[0][1] = 0;     // set the adjacent right of the first cell as an obstacle
                         solution_matrix[0][1] = 0; // delete the adjacent right of the first cell from the solution path
                         y_coordinate = 0;         // and go back to first cell 
                     }
                     is_two_side_passable = false; // set is_two_side_passable to false since one side is already visited
                 }
             }
        }
        solution_matrix[x_coordinate][y_coordinate] = 1; // set current cell as part of the solution path
    }
    //set the first and last cell of the solution matrix as part of the path
    solution_matrix[0][0] = 1; 
    solution_matrix[dimension-1][dimension-1] = 1;
  
    // iterate through every column of every cell of the resultant matrix
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
            cout<<solution_matrix[i][j]<<" "; // display the value of the current cell
        cout<<endl;
    }
    
    return 0;
}