#include <iostream>
#include <cmath>

int main()
{
	int n;
	std::cin>>n;
	int arr[n];
    int all = 0;
	for (int i = 0; i < n; ++i){
		std::cin>>arr[i];
        all += arr[i];
	}
    int middle = 0;
    int bajtekGot = all;
    int bajtosiaGot = 0;
    for (int i = 0; i < n; ++i) {      
        if (bajtosiaGot == bajtekGot){
            middle = i;
            break;
        }
        bajtosiaGot += arr[i];
        bajtekGot -= arr[n-1-i];
    }
/*    bajtekGot = n - middle;
    bajtosiaGot = middle;*/
    if (bajtekGot == bajtosiaGot){
    	bajtekGot--;
    	bajtosiaGot++;
    }
    std::cout<<bajtosiaGot<< " " <<bajtekGot<<std::endl;

	return 0;
}