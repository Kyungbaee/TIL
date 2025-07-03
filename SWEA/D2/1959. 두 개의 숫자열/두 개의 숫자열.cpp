#include <iostream>

using namespace std;

int A[21], B[21];

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	
	for(int i=1; i<=T; i++)
	{
		int n, m, answer = 0;
		cin >> n >> m;
		
		for(int idx=1; idx<=n; idx++) cin >> A[idx];
		for(int idx=1; idx<=m; idx++) cin >> B[idx];
		
		for(int padding=0; padding<=abs(n-m); padding++){
			int sum = 0;
			if(n<m) for(int idx=1; (idx<=n)&&(idx+padding<=m); idx++) sum += (A[idx]*B[idx+padding]);
			else for(int idx=1; (idx+padding<=n)&&(idx<=m); idx++) sum += (A[idx+padding]*B[idx]);
			if(answer < sum) answer = sum;
		}
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}