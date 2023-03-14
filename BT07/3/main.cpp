#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

int GetRandom(int min, int max)
{
	return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

string card[52];
int numberCard[5];
string inQuanBai(int khoa)
{
    return card[khoa];
}

//neu khoa1 uu tien hon khoa2
bool uuTienHon(int khoa1, int khoa2)
{
    if(card[khoa1][0]>card[khoa2][0]) return 1;
    else if(card[khoa1][0]<card[khoa2][0]) return 0;
    else
    {
        if(card[khoa1][2]=='b') return 0;
        else if(card[khoa2][2]=='b') return 1;
        else if(card[khoa1][2]=='t') return 0;
        else if(card[khoa2][2]=='t') return 1;
        else if(card[khoa1][2]=='r') return 0;
        else if(card[khoa2][2]=='r') return 1;
        else if(card[khoa1][2]=='c') return 0;
        else if(card[khoa2][2]=='c') return 1;
    }
}

int deck[52];
int playerDeck[5][14];

void traoBai(int *boBai)
{
    srand((unsigned int)time(NULL));
    bool check[52]={0};
    int cnt=0;
    int temp;
    for(int i=0;i<52;i++)
    {
        temp=GetRandom(0,51);
        if(check[temp]==0)
        {
            boBai[i]=temp;
            check[temp]=1;
        }
        else
        {
            i--;
        }
    }
}

void chiaBai(int *boBai, int **boBaiNguoiChoi)
{
    int temp;
    temp=1;
    for(int i=0;i<52;i+=4)
    {
        playerDeck[1][temp]=deck[i];
        temp++;
    }
    temp=1;
    for(int i=1;i<52;i+=4)
    {
        playerDeck[2][temp]=deck[i];
        temp++;
    }
    temp=1;
    for(int i=2;i<52;i+=4)
    {
        playerDeck[3][temp]=deck[i];
        temp++;
    }
    temp=1;
    for(int i=3;i<52;i+=4)
    {
        playerDeck[4][temp]=deck[i];
        temp++;
    }

}

void inBoBaiNguoiChoi(int *boBaiNguoiChoi)
{
    cout<<"Player 1: ";
    for(int i=1;i<=13;i++)
    {
        cout<<playerDeck[1][i]<<" ";
    }
    cout<<endl;
    cout<<"Player 2: ";
    for(int i=1;i<=13;i++)
    {
        cout<<playerDeck[2][i]<<" ";
    }
    cout<<endl;
    cout<<"Player 3: ";
    for(int i=1;i<=13;i++)
    {
        cout<<playerDeck[3][i]<<" ";
    }
    cout<<endl;
    cout<<"Player 4: ";
    for(int i=1;i<=13;i++)
    {
        cout<<playerDeck[4][i]<<" ";
    }
    cout<<endl;
}

int aiCo2Bich(int **inBoBaiNguoiChoi)
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(playerDeck[i][j]==0) return i;
        }
    }
}

int chonBai(int *boBaiNguoiChoi)
{
    srand((unsigned int)time(NULL));
    int temp=GetRandom(1,13);
    return temp;
}

void choiBai(int *boBaiNguoiChoi, int quanBaiVuaChoi)
{
    int temp=chonBai(deck);
    if(uuTienHon(temp,quanBaiVuaChoi))
    {
        cout<<card[temp]<<endl;
    }
}

void nguoiChoiTiepTheo(int turn)
{
    turn++;
    if(turn==5) turn =1;
}

int main()
{
	card[0] = "2 bich";
	card[1] = "3 bich";
	card[2] = "4 bich";
	card[3] = "5 bich";
	card[4] = "6 bich";
	card[5] = "7 bich";
	card[6] = "8 bich";
	card[7] = "9 bich";
	card[8] = "10 bich";
	card[9] = "J bich";
	card[10] = "Q bich";
	card[11] = "K bich";
	card[12] = "A bich";
	card[13] = "2 tep";
	card[14] = "3 tep";
	card[15] = "4 tep";
	card[16] = "5 tep";
	card[17] = "6 tep";
	card[18] = "7 tep";
	card[19] = "8 tep";
	card[20] = "9 tep";
	card[21] = "10 tep";
	card[22] = "J tep";
	card[23] = "Q tep";
	card[24] = "K tep";
	card[25] = "A tep";
	card[26] = "2 ro";
	card[27] = "3 ro";
	card[28] = "4 ro";
	card[29] = "5 ro";
	card[30] = "6 ro";
	card[31] = "7 ro";
	card[32] = "8 ro";
	card[33] = "9 ro";
	card[34] = "10 ro";
	card[35] = "J ro";
	card[36] = "Q ro";
	card[37] = "K ro";
	card[38] = "A ro";
	card[39] = "2 co";
	card[40] = "3 co";
	card[41] = "4 co";
	card[42] = "5 co";
	card[43] = "6 co";
	card[44] = "7 co";
	card[45] = "8 co";
	card[46] = "9 co";
	card[47] = "10 co";
	card[48] = "J co";
	card[49] = "Q co";
	card[50] = "K co";
	card[51] = "A co";
	traoBai(deck);
	int **playerDeck=new int*[14];
    for (int i = 0; i < 14; ++i)
    {
        playerDeck[i] = new int[14];
    }
    chiaBai(deck,playerDeck);
    inBoBaiNguoiChoi(deck);
    int turn=aiCo2Bich(playerDeck);

    for(int i=1;i<=4;i++)
    {
        numberCard[i]=13;
    }

    while(numberCard[1]!=0&&numberCard[2]!=0&&numberCard[3]!=0&&numberCard[4]!=0)
    {
        cout<<"Player "<<turn<<" danh 2 bich"<<endl;
        int pre=0;
        numberCard[turn]--;
        nguoiChoiTiepTheo(turn);
        int temp=chonBai(deck);
        if(playerDeck[turn][temp],pre)
        {
            cout<<playerDeck[turn][temp];
        }
    }
}
