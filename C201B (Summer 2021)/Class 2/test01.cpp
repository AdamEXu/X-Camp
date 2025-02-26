#include <iostream>
#include <iomanip>
using namespace std;

void fillArray(int **array,int row,int col)
{
    int i,j;
    cout<<"Enter Data in array"<<endl;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            cout<<"Enter element ["<<i<<"]["<<j<<"]: ";
            cin>>array[i][j];
        }
    }
}
void showArray(int **array,int row,int col)
{
    int i,j;
    cout<<"Table of contents"<<endl;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            cout<<setw(3)<<array[i][j];     //show row in one line
        }
        cout<<endl;
    }
}
int main()
{
    int row,col;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter col: ";
    cin>>col;

    int array[row][col];    //declare array
    fillArray(array,row,col);
    showArray(array,row,col);
    return 0;
}
