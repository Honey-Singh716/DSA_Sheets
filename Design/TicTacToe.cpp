#include <iostream>
#include <vector>

using namespace std;

enum class Symbol
{
    EMPTY,
    X,
    O
};

class Move{
    private:

    int row;
    int col;

    public:
    Move(int row,int col){
        this->row = row;
        this->col = col;
    }

    int getRow(){
        return row;
    }

    int getCol(){
        return col;
    }

};


class Cell{
    private:
    int row;
    int col;
    Symbol symbol;

    public:
    Cell(int row,int col){
        this->row = row;
        this->col = col;
        symbol=Symbol::EMPTY;
    }

    // default constructor to allow vector<Cell>(n) usage
    Cell(): row(0), col(0), symbol(Symbol::EMPTY) {}

    bool isEmpty(){
        return symbol==Symbol::EMPTY;
    }

    void setSymbol(Symbol symbol){
        this->symbol=symbol;
    }

    Symbol getSymbol(){
        return symbol;
    }

};

class Player{
    protected:
    string name;
    Symbol symbol;

    public:
    Player(string name,Symbol symbol){
        this->name = name;
        this->symbol = symbol;
    }

    string getName(){
        return name;
    }

    Symbol getSymbol(){
        return symbol;
    }

    virtual Move getMove(){
        return Move(0,0);
    }
};



class HumanPlayer : public Player{
    public:

    HumanPlayer(string name,Symbol symbol): Player(name,symbol){

    }

    Move getMove() override {
        int row,col;

        cout<<"Enter Row and Column: ";
        cin >> row>>col;

        return Move(row,col);
    }
};



class Board
{
private:
    int size;
    vector<vector<Cell>> grid;

public:

    Board(int size)
    {
        this->size = size;
        grid.resize(size, vector<Cell>(size));
    }

    int getSize()
    {
        return size;
    }

    bool isValidMove(Move move)
    {
        int r = move.getRow();
        int c = move.getCol();

        if(r < 0 || r >= size)
            return false;

        if(c < 0 || c >= size)
            return false;

        return grid[r][c].isEmpty();
    }

    bool placeMove(Move move, Symbol symbol)
    {
        if(!isValidMove(move))
            return false;

        int r = move.getRow();
        int c = move.getCol();

        grid[r][c].setSymbol(symbol);

        return true;
    }

    bool removeMove(Move move)
    {
        int r = move.getRow();
        int c = move.getCol();

        if(r < 0 || r >= size)
            return false;

        if(c < 0 || c >= size)
            return false;

        grid[r][c].setSymbol(Symbol::EMPTY);

        return true;
    }

    bool isFull()
    {
        for(auto &row : grid)
        {
            for(auto &cell : row)
            {
                if(cell.isEmpty())
                    return false;
            }
        }

        return true;
    }

    void display()
    {
        cout << "\n";

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                Symbol s = grid[i][j].getSymbol();

                if(s == Symbol::X)
                    cout << " X ";

                else if(s == Symbol::O)
                    cout << " O ";

                else
                    cout << " - ";
            }

            cout << endl;
        }

        cout << endl;
    }

    Symbol checkWinner()
    {
        // Check Rows
        for(int i = 0; i < size; i++)
        {
            Symbol first = grid[i][0].getSymbol();

            if(first == Symbol::EMPTY)
                continue;

            bool same = true;

            for(int j = 1; j < size; j++)
            {
                if(grid[i][j].getSymbol() != first)
                {
                    same = false;
                    break;
                }
            }

            if(same)
                return first;
        }

        // Check Columns
        for(int j = 0; j < size; j++)
        {
            Symbol first = grid[0][j].getSymbol();

            if(first == Symbol::EMPTY)
                continue;

            bool same = true;

            for(int i = 1; i < size; i++)
            {
                if(grid[i][j].getSymbol() != first)
                {
                    same = false;
                    break;
                }
            }

            if(same)
                return first;
        }

        // Main Diagonal
        Symbol first = grid[0][0].getSymbol();

        if(first != Symbol::EMPTY)
        {
            bool same = true;

            for(int i = 1; i < size; i++)
            {
                if(grid[i][i].getSymbol() != first)
                {
                    same = false;
                    break;
                }
            }

            if(same)
                return first;
        }

        // Anti Diagonal
        first = grid[0][size-1].getSymbol();

        if(first != Symbol::EMPTY)
        {
            bool same = true;

            for(int i = 1; i < size; i++)
            {
                if(grid[i][size-1-i].getSymbol() != first)
                {
                    same = false;
                    break;
                }
            }

            if(same)
                return first;
        }

        return Symbol::EMPTY;
    }
};


class Game{
    private:

    Board board;
    HumanPlayer player1;
    HumanPlayer player2;

    Player* currentPlayer;
    public:

    Game()
        : board(3),
          player1("Player 1",Symbol::X),
          player2("Player 2",Symbol::O)
    {
        currentPlayer=&player1;
    }

    void switchPlayer()
{
    if(currentPlayer==&player1)
        currentPlayer=&player2;
    else
        currentPlayer=&player1;
}

    void play(){
        while(true){

            board.display();

            cout<<currentPlayer->getName()<<" Turn"<<endl;

            Move move = currentPlayer->getMove();

            if(!board.placeMove(move,currentPlayer->getSymbol()))
                continue;

            Symbol winner=board.checkWinner();
            
            if(winner != Symbol::EMPTY){
                board.display();
                
                cout<<currentPlayer->getName()<<" Wins\n";
                break;
            }

            if(board.isFull()){
                board.display();
                cout<<"Draw\n";
                break;
            }
            switchPlayer();
        }
    }

};

int main(){
    Game game;
    game.play();
    return 0; 
}