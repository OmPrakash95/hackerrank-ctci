#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

long long make_change(vector<int> coins, int money) {
	int def = 0;
	int** a = new int*[coins.size()+1];
	for(int i = 0; i < coins.size()+1; ++i)
	    a[i] = new int[money+1];

	for(int i = 0; i < coins.size()+1 ; i++){
		for(int j = 0; j<= money ; j++)
			if(j == 0)a[i][j] = 1;
			else a[i][j] = 0;
	}

	for(int i=1; i < coins.size()+1 ; i++){
		for(int j = 1; j <= money ; j++){
			if(j<coins[i-1]) a[i][j] = a[i-1][j];
			else a[i][j] = a[i-1][j] + a[i][j-coins[i-1]];
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
	int result = a[coins.size()+1][money+1];
	cout<<result;
	return 0;
}
//construct 0th row
int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}