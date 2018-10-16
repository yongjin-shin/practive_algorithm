// 빨리 적다가 실수한다… 부호를 잘 적자ㅠㅡㅠ

#include<iostream>
using namespace std;

int R = 0; int C = 0;
char mp[21][21];
int check[27];
const char zero = 'A';
int best_cnt = 0;

void search(int x, int y, int cnt) {


	//down
	if (x + 1 <= R && check[mp[x + 1][y] - zero] != 1) {
		check[mp[x + 1][y] - zero] = 1;
		search(x + 1, y, cnt + 1);
	}

	//right
	if (y+1 <= C && check[mp[x][y+1] - zero] != 1) {
		check[mp[x][y + 1] - zero] = 1;
		search(x, y+1, cnt + 1);
	}

	//left
	if (1 <= y - 1 && check[mp[x][y - 1] - zero] != 1) {
		check[mp[x][y - 1] - zero] = 1;
		search(x, y - 1, cnt + 1);
	}

	//up
	if ( 1 <= x - 1 && check[mp[x - 1][y] - zero] != 1) {
		check[mp[x - 1][y] - zero] = 1;
		search(x - 1, y, cnt + 1);
	}

	check[mp[x][y] - zero] = 0;

	if (cnt >= best_cnt)
		best_cnt = cnt;

	return;
}

int main(){
	char tmp;
	cin >> R >> C;
	for (int i = 0; i < 27; i++) {
		check[i] = 0;
	}

	for (int i = 1; i < R+1; i++) {
		for (int j = 1; j < C+1; j++) {
			cin >> tmp;
			mp[i][j] = tmp;
		}
	}

	check[mp[1][1] - zero] = 1;
	search(1, 1, 1);
	cout << best_cnt;

	return 0;
}