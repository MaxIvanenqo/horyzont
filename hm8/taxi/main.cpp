#include <iostream>
#include <algorithm>

bool check(int a, int b){	
	return a > b;
}

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    
    int count = 0;
    
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    
    std::sort(arr, arr+n, check);
    
    for(int i = 0, f = 0; i < n; i++){
        if(arr[i] == 4){
            count++;
        }
        
        else if(arr[i] == 3){
            count++;
            f++;
        }
        
        else if(arr[i] == 2 && arr[i+1] == 2){
            count++;
            i++;
        }
        
        else if(arr[i] == 2 && (arr[i+1] == 1 || arr[i] == arr[n-1])){
            count++;
            f += 2;
        }
        
        else if(arr[i] == 1 && f > 0){
            f--;
        }
        
         else if(arr[i] == 1 && f == 0){
            count++;
            f+=3;
        }
        
    }
    std::cout << count << std::endl;
    return 0;
}