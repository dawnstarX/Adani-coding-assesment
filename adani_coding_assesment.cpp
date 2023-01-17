#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//function to fetch random int from 0 to 100
int fetch_number(){
    int x=rand()%101;
    return x;
}

vector<vector<int>> create_2DList(int numberOfRows,int numberOfColumns){
    
     //declaring a 2D vector(list) of size numberOfRows,numberOfColumns
   vector<vector<int>> arr( numberOfRows , vector<int> (numberOfColumns,0));
    
    //filling the 2D list with random numbers
    for (int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            arr[i][j] = fetch_number();
        }
    }
    
    return arr;
}

vector<vector<int>> sort_2DList(vector<vector<int>>arr,int columnIndex){
    //using stl for sorting
    //I have used coustom comapartor here
   sort(arr.begin(), arr.end(), [columnIndex](const vector<int>& a, const vector<int>& b) {
        return a[columnIndex] < b[columnIndex];
    });
    return arr;
}

int main()
{
    int numberOfRows,numberOfColumns,columnIndex;
    cout<<"enter number of rows and columns"<<endl;
    
    //taking input
    cin>>numberOfRows>>numberOfColumns;
    
    //declaring a 2D vector(list) of size numberOfRows,numberOfColumns
    vector<vector<int>> arr( numberOfRows , vector<int> (numberOfColumns,0));
    
    //calling the function to create a 2D list
    arr=create_2DList(numberOfRows,numberOfColumns);
    
    //printing the random generated list
    cout<<"This is the random generated 2D list between 0 to 100"<<endl;
    for (int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    //taking input for column columnIndex
    cout<<"enter column index"<<endl;
    cin>>columnIndex;
    
    //declaring a 2D vector(list) for sorted list
    vector<vector<int>> sortedList( numberOfRows , vector<int> (numberOfColumns,0));
    
    //calling the function to sort the 2D list
    sortedList=sort_2DList(arr,columnIndex);
    
    //printing the sorted 2D list
    cout<<"This is the sorted 2D list according to the column index";
    for (int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            cout<<sortedList[i][j]<<" ";
        }
        cout<<endl;
    }
    
   
    
    
    

    return 0;
}