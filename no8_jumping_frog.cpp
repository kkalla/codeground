#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
	setbuf(stdout,NULL);

	int TC;
	int test_case;
	vector<int> stones_;
	int K;

	scanf("%d",&TC);
	for(test_case=1;test_case<=TC; test_case++){
		int N;
		cin >> N;
		stones_.resize(N+1);
		stones_[0]=0;
		for(int i=1;i<N+1;++i)
			cin>>stones_[i];
		cin>>K;
		int curstone =0;
		int numjump =0;
		int laststone =0;
		while(curstone <N){
			laststone = curstone;
			while(curstone<N && stones_[curstone+1]-
					stones_[laststone]<=K)
				curstone += 1;
			if(curstone==laststone){
				numjump = -1;
				break;
			}
			if(curstone<=N)
				numjump += 1;
		}



		printf("Case #%d\n",test_case);
		cout<<numjump<<endl;
	}


	return 0;
}
