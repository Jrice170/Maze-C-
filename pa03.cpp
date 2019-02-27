/* Declare any non-required functions above main.
 * The duty of main here is to interact with the user, take in input, and manage wrapping output and runtime.
 * Remember, if you are considering putting something in main or a function, double check the specifications.
 * Each function should only do what it is specified to do, and no more.
 */

#include "maze.h"

//str.erase(std::remove(str.begin(),str.end(), '\n'), str.end());



int main()
{

    string * Maze;
    ///  number of mazes solved
    int rows;
    int pos_col,pos_row;
    cout<<"Number of rows "<<endl;
    cin>>rows;
    int map_number = 0;
    while(rows !=0)
    {

        Maze = build_matrix(rows);
        cin.ignore();
        fill_matrix(Maze,rows);
        find_start(Maze,rows,pos_col,pos_row); /// stating position for neo
        if(find_exit(Maze,pos_col,pos_row))
        {

            cout<<"Map "<<map_number<<" -- "<<"Solution found:"<<endl;

        }
        else
        {

            cout<<"Map "<<map_number<<" -- "<<"No solution found:"<<endl;

        }

        print_matrix(Maze,rows);


        delete_matrix(Maze);

        cin>>rows;
        map_number++;
    }

    return 0;
}
