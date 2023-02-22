/** \file Life.cpp
 *  \brief     Life class functions.
 *  \details   Contains class functions definitions
 *  \author    Sergei Rogov
 *  \version   0.1
 *  \date      2023-2023
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */
#include <iostream>
#include "Life.h"

using namespace std;

void Life::initialize(){
    int row, col;
    for(row=0; row<MAXROW; row++)
        for(col=0; col<MAXCOL; col++)
            grid[row][col] = dead;
    
    cout << "Enter coordinates of living cells and finish with -1 -1:\n";
    do{
        cout << "\nx = ";
        cin >> row;
        cout << "y = ";
        cin >> col;
        if (row==-1 && col==-1) cout << "Finished!\n";
        else if (row < 0 || row >= MAXROW) cout << "Row out of range!\n";
        else if (col < 0 || col >= MAXCOL) cout << "Column out of range!\n";
        else grid[row][col] = alive;
    } while(row!=-1 || col!=-1); //might be "&&" as well
}

void Life::print() const{
    int row, col;
    for(row=0; row<MAXROW; row++){
        for(col=0; col<MAXCOL; col++){
            if (grid[row][col] == dead) cout << " ";
            else cout << "*";
        }
        cout << endl;
    }        
}

void Life::update(){
    int row, col, neighbors;
    for(row=0; row<MAXROW; row++){
        for(col=0; col<MAXCOL; col++){
            neighbors = neighborCount(row, col);
            if (grid[row][col]==alive){
                if (neighbors==2 || neighbors==3) nextGrid[row][col] = alive;
                else nextGrid[row][col] = dead;
            } else {
                if (neighbors==3) nextGrid[row][col] = alive;
                else nextGrid[row][col] = dead;
            }
        }
    }
    for(row=0; row<MAXROW; row++){
        for(col=0; col<MAXCOL; col++){
            grid[row][col]=nextGrid[row][col];
        }
    }
}

int Life::neighborCount (int row, int col) const{
    int count = 0;
    count += explore(row-1, col-1);
    count += explore(row, col-1);
    count += explore(row+1, col-1);
    count += explore(row+1, col);
    count += explore(row+1, col+1);
    count += explore(row, col+1);
    count += explore(row-1, col+1);
    count += explore(row-1, col);
    return count;
}

int Life::explore (int row, int col) const{
    bool RowIsInBounds = (row >= 0 || row < MAXROW);
    bool ColIsInBounds = (col >= 0 || col < MAXCOL);
    if (!RowIsInBounds || !ColIsInBounds) return 0;
    if (grid[row][col] == alive) return 1;
    return 0;
}