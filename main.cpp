#include"ChessBoard.h"
#include"Player.h"
 
int main()
{
    ChessBoard board;
    //stone of Player aaa'*'
    Player playA("aaa",'*');
    playA.attachToBoard(&board);
    //stone of Player bbb'#'
    Player playB("bbb",'#');
    playB.attachToBoard(&board);    
    board.show();
    while(1)
    {
        //Player A place a stone
        playA.setChess();
        if(playA.isWin())
        {   cout<<"Winer!"; break;}       
        board.show();
 
        //Player B place a stone
        playB.setChess();
        if(playB.isWin())
        {   cout<<"Winer!"; break;}   
        board.show();
    }
    return 1;
}
