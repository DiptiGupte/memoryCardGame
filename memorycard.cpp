#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void instructions();

int main()
{
  instructions();

  //create board game
  char board[4][4];
  for(int r = 0; r < 4; r++)
  {
    for(int c = 0; c < 4; c++)
    {
      board[r][c] = '*';
    }
  }
  cout<<"  ";
  for(char i = 'A'; i <= 'D'; i++)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  for(int j = 1; j <= 4; j++)
  {
    cout<<j<<" ";
    for(int k = 0; k < 4; k++)
    {
      cout<<board[j - 1][k]<< " ";
    }
    cout<<endl;
  }
  int foundPairs = 0;

  //get cards
  int card[4][4];
  vector<int> nums;
  for(int i = 0; i < 2; i++)
  {
    for(int j = 1; j <= 8; j++)
    {
      nums.push_back(j);
    }
  }
  srand((unsigned)time(NULL));
  int index;
  for(int row = 0; row < 4; row++)
  {
    for(int col = 0; col < 4; col++)
    {
      index = rand() % nums.size();
      card[row][col] = nums[index];
      nums.erase(nums.begin() + index);
    }
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      cout<<card[i][j];
    }
    cout<<endl;
  }

  //play game
  while(foundPairs != 8)
  {
    char centry1, centry2;
    int ientry1, ientry2;
    cout<<"Enter the first card you would like to pick (put a space between the uppercase letter and number): ";
    cin>>centry1>>ientry1;
    cout<<"Enter the second card you would like to pick (put a space between the uppercase letter and number): ";
    cin>>centry2>>ientry2;
    //doing centry1 - '0' - 17 and centry2 - '0' - 17 to get the int values of the locations given
    cout<<"You picked "<<card[ientry1 - 1][centry1 - '0' - 17]<<" and "<<card[ientry2 - 1][centry2 - '0' - 17]<<endl;
    //if picked matching cards
    if(card[ientry1 - 1][centry1 - '0' - 17] == card[ientry2 - 1][centry2 - '0' - 17])
    {
      foundPairs++;
      board[ientry1 - 1][centry1 - '0' - 17] = '0' + card[ientry1 - 1][centry1 - '0' - 17]; //to get correct char value
      board[ientry2 - 1][centry2 - '0' - 17] = '0' + card[ientry1 - 1][centry1 - '0' - 17]; //to get correct char value
      //print new board
      cout<<"  ";
      for(char i = 'A'; i <= 'D'; i++)
      {
        cout<<i<<" ";
      }
      cout<<endl;
      for(int j = 1; j <= 4; j++)
      {
        cout<<j<<" ";
        for(int k = 0; k < 4; k++)
        {
          cout<<board[j - 1][k]<<" ";
        }
        cout<<endl;
      }
    }
  }
  cout<<"Congrats! You won!!"<<endl;
  return 0;
}

void instructions()
{
  cout<<"Welcome to the Memory Card Game!"<<endl;
  cout<<"Here's how you play:"<<endl;
  cout<<"\t- There are two pairs of each type of card from 1 to 8."<<endl;
  cout<<"\t- Type out two postitions (e.g. A2 D4)"<<endl;
  cout<<"\t- If the two cards match, you will get to keep them, if not they will turn back around."<<endl;
  cout<<"\t- The game is over when all the cards are matched."<<endl;
}
