#include<iostream>
#include<queue>
using namespace std;

void Print_chess(int array[][3]){
	cout << " 0  " << 1 << "   " << 2 << "  " << 3 << "  ";
	cout << endl;
	for (int i = 0; i < 3; ++i){
		cout << "———————" << endl;
		cout << i << " ";
		for (int j = 0; j < 3; ++j){
			if (array[i][j] == 1){
				cout<< "| " << "O ";
			}
			if (array[i][j] == 0){
				cout<< "| " << "  " ;
			}
			if (array[i][j] == -1){
				cout<< "| " << "X ";
			}
		}
		cout << endl;
	}
	cout << "———————" << endl;
}

int Is_win(int array[][3]){
	int temp = 0;
	if (array[0][0] + array[0][1] + array[0][2] != 0){
		temp = array[0][0] + array[0][1] + array[0][2];
	}
	if (array[1][0] + array[1][1] + array[1][2] != 0){
		temp = array[1][0] + array[1][1] + array[1][2];
	}
	if (array[2][0] + array[2][1] + array[2][2] != 0){
		temp = array[2][0] + array[2][1] + array[2][2];
	}
	if (array[0][0] + array[1][1] + array[2][2] != 0){
		temp = array[0][0] + array[1][1] + array[1][2];
	}
	if (array[0][2] + array[1][1] + array[2][0] != 0){
		temp = array[0][2] + array[1][1] + array[2][0];
	}
	if (temp != 3 && temp != -3){
		temp = 0;
	}
	return temp;
}

bool Isplayrwin(int array[][3]){
	if (Is_win(array)){
		return true;
	}
	return false;
}

void Play_game(){
	
}

struct inode{
	inode(int x = 0, int y = 0)
		:_x(x)
		, _y(y){}
	int _x;
	int _y;
};

void clear_queue(queue<inode>& q){
	while (!q.empty()){
		q.pop();
	}
}

int main(){
	int array[3][3] = { { 0, 1, 1 }, { -1, 0, 1 }, { 0, 1, -1 } };
	memset(array, 0 ,sizeof(int)* 3 * 3);
	Print_chess(array);
	int player = 1;
	queue<inode> q;
	while (true){
		cout << "请玩家输入坐标：";
		int x;
		int y;
		cin >> x >> y;
		if (x <= 0 || x > 3 || y <= 0 || y > 3){
			cout << "请重新输入坐标:" << endl;
			continue;
		}
		if (!Isplayrwin(array) && player == 1){
			//l号玩家玩
			array[x - 1][y - 1] = 1;
			player = -1;
		}
		else if (!Isplayrwin(array) && player == -1){
			array[x - 1][y - 1] = -1;
			player = 1;
		}
		if (Isplayrwin(array)){
			int temp = Is_win(array);
			if (temp == -3){
				cout << "player1是否愿意再来一盘：" << endl;
				char input = '0';
				cin >> input;
				if (input == 'Y'){
					memset(array, 0, sizeof(int)* 3 * 3);
					clear_queue(q);
					Print_chess(array);
					player = 1;
					continue;
				}
				else{
					break;
				}
			}
			if (temp == 3){
				cout << "player2是否愿意再来一盘：" << endl;
				char input = '0';
				cin >> input;
				if (input == 'Y'){
					player = -1;
					memset(array, 0, sizeof(int)* 3 * 3);
					clear_queue(q);
					continue;
				}
				else{
					break;
				}
			}
		}
		inode temp;
		temp._x = x - 1;
		temp._y = y - 1;
		if (q.size() == 6){
			inode cur = q.front();
			array[cur._x][cur._y] = 0;
			q.pop();
		}
		q.push(temp);
		Print_chess(array);
		
		
	}
	if (player == -1){
		cout << "player1 win" << endl;
	}
	else{
		cout << "player2 win" << endl;
	}
	system("pause");
	return 0;
}
