//c++


#include<bits/stdc++.h>
using namespace std;
void findmax (int a[], int n){
	cout << *max_element(a, a+n) << endl;
}

void findmin (int a[], int n){
	cout << *min_element(a, a+n) << endl;
}

void findmaxsegment (int a[], int x, int y){
	cout << *max_element(a+x, a+y+1) << endl;
}

void sum(int a[], int n){
	int tong = 0;
	for(int i = 0; i < n; i++){
		tong += a[i];
	}
	cout << tong << endl;
}

int main(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	char term; cin >> term;
	string s;
	while (true){
		cin >> s;
		if (s == "***"){
			break;
		} else if (s == "find-max") {
			findmax(a, n);
		} else if (s == "find-min") {
			findmin(a, n);
		} else if (s == "find-max-segment"){
			int x, y; cin >> x >> y;
            findmaxsegment(a, x-1, y-1);
		} else if (s == "sum"){
			sum(a, n);
		}
	}
	return 0;
}
