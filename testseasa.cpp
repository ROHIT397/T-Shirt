// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
// 	string time;
// 	getline(cin, time);

// 	string timeOne, timeTwo;

// 	int hourOne = 0, hourTwo = 0, minuteOne = 0, minuteTwo = 0;
// 	bool hour = false;

// 	int i;

// 	for (i = 0; time[i] != '-'; i++)
// 	{
// 		if (time[i] == ':')
// 		{
// 			hour = true;
// 			continue;
// 		}
// 		if (time[i] == 'a' || time[i] == 'p')
// 		{
// 			timeOne.push_back (time[i]);
// 			timeOne.push_back (time[i + 1]);
// 		}
// 		if ( hour && time[i] >= '0' && time[i] <= '9')
// 			minuteOne  = (minuteOne  * 10) + (time[i] - '0');
// 		else if (time[i] >= '0' && time[i] <= '9')
// 			hourOne = (hourOne * 10) + (time[i] - '0');
// 	}

// 	hour = false;
// 	for (i = i + 1; i < time.length(); i++)
// 	{
// 		if (time[i] == ':')
// 		{
// 			hour = true;
// 			continue;
// 		}
// 		if (time[i] == 'a' || time[i] == 'p')
// 		{
// 			timeTwo.push_back(time[i]);
// 			timeTwo.push_back(time[i + 1]);
// 		}
// 		if (hour && time[i] >= '0' && time[i] <= '9')
// 			minuteTwo = (minuteTwo * 10) + (time[i] - '0');
// 		else if (time[i] >= '0' && time[i] <= '9')
// 			hourTwo = (hourTwo * 10) + (time[i] - '0');
// 	}

// 	int hr = 0;
// 	if (hourOne == hourTwo && timeOne == timeTwo && minuteOne > minuteTwo )
// 		hr = 24 - hourOne - hourTwo ;
// 	else if (hourOne > hourTwo && timeOne == timeTwo && minuteOne < minuteTwo )
// 		hr = 24 - hourOne - hourTwo ;
// 	else if (timeOne == timeTwo || (hourTwo == 12 && hourOne != 12))
// 		hr = hourTwo - hourOne;
// 	else
// 		hr = 12 - hourOne + hourTwo ;

// 	int totalminute;
// 	if (minuteOne != 0)
// 		totalminute = (hr * 60 - minuteOne + minuteTwo );
// 	else
// 		totalminute = (hr * 60 + minuteOne + minuteTwo );
// 	cout << totalminute;
// }


#include<bits/stdc++.h>
using namespace std;
#define l long int
string palindromee(string &s, string &t)
{
	int n = s.size();
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string res = "";
	int i = n, j = n;
	while (i > 0 && j > 0)
	{
		if (s[i - 1] == t[j - 1])
		{
			res += s[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])  i--;
		else j--;

	}
	return res;

}
int main()
{
	string s; cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	string pal = palindromee(s, t);

	if (s == t) cout << "palindrome";
	else if (pal.length() < 3)  cout << "not possible";
	else if (s.length() - pal.length() > 2)  cout << "not possible";
	else
	{
		string res = "";
		int i = 0, j = 0;
		while (i < s.length() || j < pal.length())
		{
			if (s[i] == pal[j]) i++, j++;
			else res += s[i], i++;
		}
		cout << res;
	}
}