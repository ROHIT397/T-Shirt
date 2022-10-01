#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long int ll;

int aa(string s1, string s2) {
	int arr[26] = {0};
	for (int i = 0; i < s1.size(); i++) {
		arr[s1[i] - 'a']++;

	}
	int res = 0;
	for (int i = 0; i < s2.size(); i++) {
		if (arr[s2[i] - 'a'] > 0)
		{
			res++;
			arr[s2[i] - 'a']--;
		}

	}
	return res;
}

int main()
{
	string s1 = "hello";
	string s2 = "world";
	cout << aa(s1, s2);

}