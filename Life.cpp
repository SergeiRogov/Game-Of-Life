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
        cin >> row >> col;
        if (row==-1 && col==-1) cout << "Finished!\n";
        if (row < 0 || row >= MAXROW) cout << "Row out of range!\n";
        if (col < 0 || col >= MAXCOL) cout << "Column out of range!\n";
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
    int row, col;
}

int Life::neighborCount (int, int) const{
    int row, col;
    return 1;
}