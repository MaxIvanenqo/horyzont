/*Zadanie

Napisz program mnożący dwie długie liczby.
Wejście

W pierwszym wierszu znajduje się liczba naturalna n, nie większa od 10000.

W każdym z kolejnych dwóch wierszy znajduje się jedna n-cyfrowa liczba naturalna.
Wyjście

W jedynym wierszu wyjścia ma się znaleźć jedna liczba naturalna równa iloczynowi liczb podanych w drugim i trzecim wierszu.
Przykład

Dla danych wejściowych

10
1010101010
2000000000

poprawną odpowiedzią jest

20202020200000000000*/



#include<bits/stdc++.h> 
using namespace std; 
string multiply(int a[], int b[], int n) 
{ 
	/*int n1 = num1.size(); 
	int n2 = num2.size(); */
	if (n == 0) 
		return "0"; 

	vector<int> result(n*2, 0); 

	int i_n1 = 0; 
	int i_n2 = 0; 

	for (int i = n-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = a[i]; 
		i_n2 = 0; 
		for (int j=n-1; j>=0; j--) { 
			int n2 = b[j]; 
			int sum = n*n + result[i_n1 + i_n2] + carry; 
			carry = sum/10; 
			result[i_n1 + i_n2] = sum % 10; 
			i_n2++; 
		} 

		if (carry > 0) 
			result[i_n1 + i_n2] += carry; 
		i_n1++; 
	}  
	int i = result.size() - 1; 
	while (i>=0 && result[i] == 0) 
	i--; 
	if (i == -1) 
	return "0"; 
	string s = ""; 
	
	while (i >= 0) 
		s += std::to_string(result[i--]); 

	return s; 
} 

int main() 
{ 
	int n;
	cin>>n;
	int * a = new int[n];
	int * b = new int[n];

	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	for (int j = 0; j < n; j++){
		cin>>b[j];
	}

	cout << multiply(a, b, n); 
	delete[] a;
	delete[] b;
	return 0; 
} 
