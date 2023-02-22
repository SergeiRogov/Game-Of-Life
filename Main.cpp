/** \file main.cpp
 *  \brief     The Game of Life driver.
 *  \details   The main function of The Game of Life
 *  \author    Sergei Rogov
 *  \version   0.1
 *  \date      2023-2023
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include "Life.h"
#include "utils.h"

using namespace std;

/**
 * The <code>main</code> is the driver function that kick-starts the
 * application.
 * <BR>
 * @return Returns <code>0</code> on success, any other value otherwise.
 */
int main(){
    cout << "START!\n";
    Life configuration;
    configuration.initialize();
    configuration.print();
    cout << "Continue viewing new generations?" << endl;
    while (userSaysYes()){
        configuration.update();
        configuration.print();
        cout << "Continue viewing new generations?" << endl;
    }
return 0;
}

// To run
// g++ Main.cpp Life.cpp utils.cpp
// ./a.out
