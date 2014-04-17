/* Copyright 2014 Wojciech Matusiak
 *
 * This file is part of CellularAutomatonCreator.
 *
 * CellularAutomatonCreator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CellularAutomatonCreator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CellularAutomatonCreator.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef CELLINFO_HPP
#define CELLINFO_HPP

#include <cstring>
#include <iostream>
#include <QString>

typedef unsigned char StatusT;



const int STATUS_NUMBER = 32;



class CellInfo {
private:
    StatusT neighborhood[STATUS_NUMBER];
    StatusT myStat;
    StatusT k;
public:
    CellInfo();

    StatusT me() const;
    StatusT &meRef();
    StatusT get(int s) const;
    StatusT &getRef(int s);

    friend std::ostream &operator<< (std::ostream &out, const CellInfo obj);
};

#endif // CELLINFO_HPP
