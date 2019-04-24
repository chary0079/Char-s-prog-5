#include"Player.h"
 
bool Player::isInChessBoard(int x,int y)
{
    if(x<ROW-1 && x>0 && y<COL-1 && y>0)
        return true;
    else
        return false;
}
bool Player::isLine(int x,int y)
{
    for(int direc=HORIZON;direc<=LEFTTOPTORIGHTBOTTOM;direc++)
    {
        //cnt:number of stones in one chain, it will win if one player has five stones
        int tempX,tempY,cnt=1;
        for(int i=-4;i<=4;i++)
        {
            if(i==0)continue;
            switch(direc)
            {
            case HORIZON:
                tempX=x;    tempY=y+i;      break;
            case VERTICAL:  
                tempX=x+i;  tempY=y;        break;
            case LEFTBOTTOMTORIGHTTOP:
                tempX=x-i;  tempY=y+i;      break;
            case LEFTTOPTORIGHTBOTTOM:
                tempX=x+i;  tempY=y+i;      break;
            }
            if(isInChessBoard(tempX,tempY) && m_ptBoard->m_cSquare[tempX][tempY]==m_chessType)
                cnt++;
            else
                cnt=0;
            //five stones
            if(cnt==5)
                return true;
        }
    }return false;
}
 
void Player::setChess()
{   
    cout<<"Please type coordinate of Player"<<m_name<<"x and y："<<endl;
    cin>>m_x>>m_y;
    //input is not int or there is already has a stone
    while(cin.fail() || m_ptBoard->m_cSquare[m_x][m_y]!=' ')
    {
        cout<<"Invalid input, please type coordinate of Player"<<m_name<<"x and y again："<<endl;
        cin.clear();
        cin.sync();
        cin>>m_x>>m_y;
    }
    if(isInChessBoard(m_x,m_y))
        m_ptBoard->m_cSquare[m_x][m_y]=m_chessType;  
}
 
bool Player::isWin()
{   
    return isLine(m_x,m_y)?true:false;
}