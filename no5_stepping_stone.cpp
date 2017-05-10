#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000009;

int dp[50001][101];
int answer[50001];



int main(int argc, char** argv){
	//freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int T;
	int test_case;
	int mine;

	scanf("%d",&T);
	for(test_case=1;test_case<=T;test_case++){
		int N,K,L;
		cin>>N>>K>>L;
		vector<bool> mines_(N+1,false);
		if(L>0){
			for(int i=0;i<L;++i){
			cin>>mine;
			mines_[mine]=true;
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = answer[0] = 1;

		for(int i=1;i<=N;++i)
		{
			answer[i] = 0;
			if(mines_[i])
				continue;

			for(int j=1;j<=K&&(i>=j);++j){
				dp[i][j] = ((answer[i-j]+MOD)-dp[i-j][j]) %MOD;
				answer[i] = (answer[i]+dp[i][j])%MOD;
			}
		}
		

		printf("Case #%d\n",test_case);
		cout<<answer[N]<<endl;
	}

	return 0;
}
