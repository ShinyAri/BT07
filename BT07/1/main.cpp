#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int GetRandom(int min, int max)
{
	return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

int main()
{
	srand((unsigned int)time(NULL));

	int tong1 = 0, tong2 = 0;
	int turn = 1;
	while (tong1 < 100 && tong2 < 100)
	{
		int temp;
		temp = GetRandom(1, 6);
		if (turn == 1)
		{
			tong1 += temp;
			cout << "xuc xac nguoi choi 1: " << temp << " 	" << "Tong nguoi 1: " << tong1 << endl;
			turn = 2;
		}
		else
		{
			tong2 += temp;
			cout << "xuc xac nguoi choi 2: " << temp << " 	" << "Tong nguoi 2: " << tong2 << endl;
			turn = 1;
		}
	}
	if (tong1 >= 100)
	{
		cout << "Nguoi choi 1 thang!";
	}
	else cout << "Nguoi choi 2 thang!";

	return 0;
}
