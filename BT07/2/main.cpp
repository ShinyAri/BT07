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

	int vt = 0, vr = 0;
	while (vt < 70 && vr < 70)
	{
		int temp1, temp2;
		temp1 = GetRandom(1, 10);
		temp2 = GetRandom(1, 10);
		if (temp1 >= 1 && temp1 <= 5)
		{
			vr += 3;
		}
		else if (temp1 >= 6 && temp1 <= 7)
		{
			vr -= 6;
			if (vr < 0)vr = 0;
		}
		else
		{
			vr += 1;
		}
		if (temp2 >= 1 && temp2 <= 2)
		{
			vt += 0;
		}
		else if (temp2 >= 3 && temp2 <= 4)
		{
			vt += 9;
		}
		else if (temp2 == 5)
		{
			vt -= 12;
			if (vt < 0) vt = 0;
		}
		else if (temp2 >= 6 && temp2 <= 8)
		{
			vt += 1;
		}
		else
		{
			vt -= 2;
			if (vt < 0) vt = 0;
		}
		cout << "Vi tri: R(" << vr << ") & T(" << vt << ")" << endl;
	}
	if (vt >= 70 && vr >= 70)
	{
		cout << "Hoa!";
	}
	else if (vt >= 70 && vr < 70) cout << "Tho thang!";
	else cout << "Rua thang!";
}
