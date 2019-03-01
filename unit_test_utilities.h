#ifndef UNITTEST_H
#define UNITTEST_H

#include "maze.h"
#include <fstream>

// USEFUL FUNCTIONS, NOT UNIT TESTS //
std::string rfcas(const std::string FILE_PATH)
{
    std::string contents;
    std::ifstream fin;
    fin.open(FILE_PATH.c_str());
    if(fin)
    {
        getline(fin, contents, '\0');
    }
    else
    {
        fin.clear();
    }
    fin.close();
    return contents;
}

string* convert(int start_y)
{
    string maze = rfcas("unit_test_fstream_readin.txt");
    string *matrix = new string [27];
    for(int i = 0; i < 27; i++)
    {
        for(int j = 0; j < 78; j++)
        {
            int index = j + 78*(i+start_y);
            if(maze[index] != '\n')
            {
                matrix[i] += maze[index];
            }
        }
    }
    return matrix;
}

// these are specifically for the two maps which are 27 by 77
string* key_input(int i)
{
    return convert(i*27);
}

string* key_output(int i)
{
    return convert(54+i*27);
}


#endif 
