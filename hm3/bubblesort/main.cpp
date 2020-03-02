#include <iostream>

inline bool loop(int arr[], int i){
  bool x = false;
  for(int j = 0; j < i; j++)
    if(arr[j] > arr[j + 1]){
      int tmp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = tmp;
      x = true;
    }
  return x;
}

inline void print(int arr[], int n){
  for(int i = 0; i < n; i++) 
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

inline void strangeBubbleSort(int arr[], int n){
  for(int i = n - 1; i >= 1; i--)
    if (loop(arr, i)) 
      print(arr, n);
}

int main(){
  int n;
  std::cin >> n; 
  int * arr = new int[n];
  for(int i = 0; i < n; i++)
    do std::cin >> arr[i]; 
      while(arr[i] < 1 || arr[i] > 1000000000);
  strangeBubbleSort(arr, n);
  return 0;
}