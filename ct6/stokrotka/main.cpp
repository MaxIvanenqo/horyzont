#include <iostream>
#include <utility>

using namespace std;

int stokrotki[1000][1000];
int licz[1000][1000];

int main(){
	int t;
	cin>>t;
	while(t--){
		int w, h;
		cin>>w>>h;
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++)
				cin>>stokrotki[i][j];
		}
		licz[0][0] = stokrotki[0][0];
		for (int i = 1; i < w; i++){
			licz[i][0] = licz[i-1][0] + stokrotki[i][0];
		}
		for (int j = 1; j < h; j++){
			licz[0][j] = licz[0][j-1] + stokrotki[0][j];
		}
		for (int i = 1; i < w; i++)
			for (int j = 1; j < h; j++)
				licz[i][j] = max(licz[i-1][j], licz[i][j-1]) + stokrotki[i][j];
		cout<<licz[w-1][h-1]<<endl;
	}
	return 0;
}