#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    int w, t;
    cin >> T;
    while (T--)
    {
        int days = 0;
        cin >> w >> t;
        for (; w > 120; w -= t, days++)
            ;
        cout << days << endl;
    }
    return 0;
}