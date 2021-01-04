#include<bits/stdc++.h>
using namespace std ;

class game
{
public:
    char p1, p2;
    char board[3][3];
    game(char);
    bool check_moves(char [3][3]);
    int calc_val(char [3][3]);
    int minimax(char [3][3], bool turn);
    void play_best_move();
    void display_board();
};

game :: game(char ch = 'x')
{
    p1 = (ch == 'x'? 'o': 'x');
    p2 = (p1=='x'? 'o': 'x' );
    cout<<"You are playing as '"<<ch<<"'\n";
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = '_';
        }
    }
}

bool game :: check_moves(char t_board[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(t_board[i][j]=='_') return true;
        }
    }
    return false;
}

int game :: calc_val(char t_board[3][3])
{
    for(int i=0;i<3;i++)
    {
        if(t_board[i][0] ==  t_board[i][1] && t_board[i][1] == t_board[i][2])
        {
            if(t_board[i][0] == p1) return 10;
            else if(t_board[i][0] == p2) return -10;
        }
    }

    for(int i=0;i<3;i++)
    {
        if(t_board[0][i] == t_board[1][i] && t_board[1][i] == t_board[2][i])
        {
            if(t_board[0][i] == p1) return 10;
            else if(t_board[0][i] == p2) return -10;
        }
    }

    if(t_board[0][0] == t_board[1][1] && t_board[1][1] == t_board[2][2])
    {
        if(t_board[0][0] == p1) return 10;
        else if(t_board[0][0] == p2) return -10;
    }

    if(t_board[0][2] == t_board[1][1] && t_board[1][1] == t_board[2][0])
    {
        if(t_board[0][2] == p1) return 10;
        else if(t_board[0][2] == p2) return -10;
    }
    return 0;
}


int game :: minimax(char t_board[3][3], bool turn)
{
    int score = calc_val(t_board); //cout<<score<<endl;
    if(score == 10) return score;
    if(score == -10) return score;
    if(check_moves(t_board)==false) return 0;

    if(turn)
    {
        int best = -1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(t_board[i][j] == '_')
                {
                    t_board[i][j] = p1;
                    best = max(best, minimax(t_board, !turn));
                    t_board[i][j] = '_';
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(t_board[i][j] == '_')
                {
                    t_board[i][j] = p2;
                    best = min(best, minimax(t_board, !turn));
                    t_board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

void game :: play_best_move()
{
    int x,y;
    int reward = -1000, temp;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == '_')
            {
                board[i][j] == p1;
                temp = minimax(board, false);
                cout<<temp<<endl;
                board[i][j] = '_';
                if(reward < temp)
                {
                    x = i;
                    y = j;
                    reward = temp;
                }
            }
        }
    }
    board[x][y] = p1;
}

void game :: display_board()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    char ch, again='Y';
    int x,y;
    cout<<"Enter the player you want to play as (o/x)\n";
    cin>>ch;
    game g(ch);
    while(true)
    {
        cout<<"Enter the move you want to play\n";
        cin>>x>>y;
        --x, --y;
        if(g.board[x][y] == '_')
        {
            g.board[x][y] = g.p2;
            if(!g.check_moves(g.board))
            {
                cout<<"Game over!!\n\n";
                break;
            }
            g.play_best_move();
        }
        else
        {
            cout<<"Invalid move! Enter again\n";
            continue;
        }
        g.display_board();
    }
    /*
    game g('x');
    char board[3][3] = {
                        { 'o', 'o', 'x' },
                        { '-', 'x', '_' },
                        { 'x', 'x', 'o' },
                     };
    cout<<g.calc_val(board);
    */
    return 0;
}

