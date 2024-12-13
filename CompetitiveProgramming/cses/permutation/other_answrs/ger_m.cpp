#include <bits/stdc++.h>
#define endl '\n'
#define _op                                                                    \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);                                                                  \
  cout.tie(0);
typedef long long int ll;
using namespace std;

int main() {
  _op int n;
  cin >> n;
  if (n < 4 && n > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  for (int i = 2; i <= n; i += 2)
    cout << i << " ";
  for (int i = 1; i <= n; i += 2)
    cout << i << " ";

  return 0;
}
