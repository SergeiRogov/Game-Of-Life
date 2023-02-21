/** \file utils.h
 *  \brief     Utilities file.
 *  \details   Contains helpful side functions definitions
 *  \author    Sergei Rogov
 *  \version   0.1
 *  \date      2023-2023
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */
#include <iostream>
#include "utils.h"

using namespace std;

bool userSaysYes(){
    char response;
    bool isFirstResponse = true;
    do{
        if (isFirstResponse) cout << "(y/n)?";
        else cout << "Response with either y or n:";
        isFirstResponse = false;

        do {
            cin >> response;
        } while (response=='\n' || response==' ' || response=='\t');
        
    } while (response!='y' && response!='Y' && response!='n' && response!='N');
    return (response=='y' || response=='Y'); 
}