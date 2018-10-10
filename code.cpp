#include <iostream>
#include <vector>

using namespace std;

//function that sifts element down 
void SiftDown(int& i, vector<int>& a) {
  while (2 * i + 1 < a.size()) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int j = left;
    if (right < a.size() && a[right] > a[left]) j = right;
    if (a[i] >= a[j]) break;
    swap(a[i], a[j]);
    i = j;
  }
}

//function that sifts element up
void SiftUp(int& i, vector<int>& a) {
  while (a[i] > a[(i - 1) / 2]) {
    swap(a[i], a[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

int ExtractMax(vector<int> &a) {
  int max = a[0];
  int j = 0;
  a[0] = a[a.size() - 1];
  a.erase(a.begin() + a.size() - 1);
  SiftDown(j, a);
  return max;
}

void Insert(int &i, vector<int> &a) {
  a.push_back(i);
  int j = (a.size() - 1);
  SiftUp(j, a);
}

int main() {
  int n; 
  cin >> n;
  vector<int> a;
  string command;
  for(int i = 0; i < n; i++) {
    cin >> command;
    if(command == "Insert") {
      int x;
      cin >> x;
      Insert(x, a);
      }
      if(command == "ExtractMax") {
        cout << ExtractMax(a) << endl;
      }
  }
return 0;
}
