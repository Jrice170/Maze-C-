
#include "maze.h"


void get_identity(string &my_id)
{
    my_id = "jmr3by";
}


string * build_matrix(int rows)
{
    string * new_string;
    new_string = new string[rows];
    return new_string;

}
void fill_matrix(string *matrix, int rows)
{

  std::string var;

  for(int i =0;i<rows;i++)
  {

      getline(cin,var);

      matrix[i] = var;


  }


}
void print_matrix(string *matrix, int rows)
{

    for(int i = 0;i<rows;i++)
    {

        cout<<matrix[i]<<endl;


    }

}

void delete_matrix(string *&matrix)
{

    delete [] matrix;
    matrix = nullptr;

}
void find_start(string *matrix, int rows, int &row, int &col)
{

    for(int i = 0;i < rows;i++)
    {

        if(matrix[i].find("N") != -1)
        {
            row = i;
            col = matrix[i].find("N");
            break;

        }


    }




}
/// start row x and start col y
bool find_exit(string *matrix, int row, int col)
{
    string Direct[] = {"North","South","West","East"};
    int moveup[] = {row - 1,row +1,row,row};
    int move_down[] ={col,col,col-1,col+1};
    if (at_end(matrix, row, col))
        return true;


    if(matrix[row][col] == ' ')
        matrix[row][col] = '@';

    for(int b=0;b<4;b++)
    {
      if (valid_move(matrix, row, col,Direct[b]) && find_exit(matrix, moveup[b],move_down[b]))
      {
          if(matrix[row][col] == ' ')
              matrix[row][col] = '@';
              return true;
      }

    }

  if(matrix[row][col] == '@')
      matrix[row][col] = ' ';
  return false;
}

bool at_end(string *matrix, int row, int col)
{

    return (matrix[row][col] == 'E');

}
bool valid_move(string *matrix, int row, int col, string direction)
{

    if(direction == "North")
    {

        if(matrix[row-1][col] == ' ' || matrix[row-1][col] == 'E')
        {

          return 1;
        }

        else
        {

          return 0;
        }


    }
    else if(direction == "West")
    {
        if(matrix[row][col-1]==' '|| matrix[row][col-1]=='E')
        {

          return 1;
        }
        else
        {

          return 0;
        }

    }
    else if(direction == "South")
    {

        if(matrix[row+1][col]==' '|| matrix[row+1][col]=='E')
        {

          return 1;
        }
        else
        {

          return 0;
        }

    }
    else if(direction == "East")
    {
        if(matrix[row][col+1] ==' ' || matrix[row][col+1]=='E')
        {

          return 1;
        }
        else
        {

          return 0;

        }

    }
    else
    {

      return false;

    }


}
