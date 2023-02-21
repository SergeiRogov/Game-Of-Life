/** \file Life.h
 *  \brief     Life header.
 *  \details   Contains class functions declarations
 *  \author    Sergei Rogov
 *  \version   0.1
 *  \date      2023-2023
 *  \bug       No bugs so far
 *  \copyright University of Nicosia.
 */
#ifndef LIFE_H
#define LIFE_H

// Global constants
const int MAXROW = 10;
const int MAXCOL = 10;

enum status {dead, alive};

class Life {
public:
    void initialize();
    void print() const;
    void update();
private:
    int neighborCount (int, int) const;
    status grid[MAXROW][MAXCOL];
};

#endif // end LIFE_H