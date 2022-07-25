#include<iostream>
#include <time.h>
using namespace std;

void check(int n, int * arr);
void print(int n, int * arr);
int insertion_simple(int n, int * arr, int count);
int insertion_quick(int n, int * arr, int count);

void main() {
	int n, c = 0, s = 0;
	cout << "Enter n > ";
	cin >> n;
	cout << "--------------------------------------------------------\nArray:\n--------------------------------------------------------\n";
	int * arr = new int[n];
	int * arr1 = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10000 + 1;
		arr1[i] = arr[i];
	}
	check(n, arr);
	check(n, arr1);
	print(n, arr);
	cout << "--------------------------------------------------------\nInsertion sort (simple):\n--------------------------------------------------------\n";
	c = insertion_simple(n, arr, c);
	print(n, arr);
	cout << "\-------------------------------------------------------\nInsertion sort (quick):\n--------------------------------------------------------\n";
	s = insertion_quick(n, arr1, s);
	print(n, arr1);
	cout << "--------------------------------------------------------\nThe number of comparison operations of simple sort: " << c << endl;
	cout << "--------------------------------------------------------\nThe number of comparison operations of quick sort: " << s << endl << endl;
	system("pause");
}

void print(int n, int * arr) {
	for (int i = 0; i < n; i++)
		cout << i << "." << arr[i] << endl;
}

void check(int n, int * arr) {
	int k = 1;
	while (k != 0) {
		k = 0;
		for (int i = 0; i < n; i++)
			for (int j = n; j > i; j--) {
				if (arr[i] == arr[j]) {
					arr[i] = rand();
					k++;
				}
			}
	}
}

int insertion_simple(int n, int * arr, int count) {
	int i, j, x;
	for (i = 1; i < n; i++) {
		x = arr[i];
		j = i - 1;
		count++;
		while ((x < arr[j]) && (j >= 0)) {
			count += 2;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = x;
		count += 2;
	}
	return count;
}

int insertion_quick(int n, int * arr, int count) {
	int d = n / 2;
	while (d > 0) {
		count++;
		for (int i = 0; i < n - d; i++) {
			count++;
			int j = i;
			while (j >= 0 && arr[j] > arr[j + d]) {
				count += 2;
				int temp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = temp;
				j--;
			}
			count += 2;
		}
		d = d / 2;
	}
	count++;
	return count;
}