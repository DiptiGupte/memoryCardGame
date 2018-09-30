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

  //play game
  while(foundPairs != 8)
  {
    char centry1, centry2;
    int ientry1, ientry2;
    cout<<"Enter the first card you would like to pick (put a space between the uppercase letter and number): ";
    cin>>centry1>>ientry1;
    //checking to see if vaid entry
    bool isValid = false;
    while(!isValid)
    {
      if(centry1 != 'A' && centry1 != 'B' & centry1 != 'C' && centry1 != 'D')
      {
        cout<<"Invalid column. Please pick a card from A to D: ";
        cin>>centry1>>ientry1;
      }
      else if(ientry1 != 1 && ientry1 != 2 && ientry1 != 3 && ientry1 != 4)
      {
        cout<<"Invalid row. Please pick a card from 1 to 4: ";
        cin>>centry1>>ientry1;
      }
      //if the card is already turned over
      else if(board[ientry1 - 1][centry1 - '0' - 17] != '*')
      {
        cout<<"This card already has a found pair. Please pick again: ";
        cin>>centry1>>ientry1;
      }
      else
      {
        isValid = true;
      }
    }
    cout<<"Enter the second card you would like to pick (put a space between the uppercase letter and number): ";
    cin>>centry2>>ientry2;
    //checking to see if vaid entry
    //checking to see if vaid entry
    bool isValid2 = false;
    while(!isValid2)
    {
      if(centry2 != 'A' && centry2 != 'B' & centry2 != 'C' && centry2 != 'D')
      {
        cout<<"Invalid column. Please pick a card from A to D: ";
        cin>>centry2>>ientry2;
      }
      else if(ientry2 != 1 && ientry2 != 2 && ientry2 != 3 && ientry2 != 4)
      {
        cout<<"Invalid row. Please pick a card from 1 to 4: ";
        cin>>centry2>>ientry2;
      }
      //if the card is already turned over
      else if(board[ientry2 - 1][centry2 - '0' - 17] != '*')
      {
        cout<<"This card already has a found pair. Please pick again: ";
        cin>>centry2>>ientry2;
      }
      //pick the same card again
      else if((centry2 == centry1) && (ientry2 == ientry1))
      {
        cout<<"You have already selected this card. Please pick a different card: ";
        cin>>centry2>>ientry2;
      }
      else
      {
        isValid2 = true;
      }
    }
    //using centry1 - '0' - 17 and centry2 - '0' - 17 to get the int values of the locations given
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
