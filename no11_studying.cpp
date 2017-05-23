#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> tests_;

void SiftDown(int i){
	int size = tests_.size();
	int maxindex = i;
	int l = 2*i + 1;
	if(l<=tests_.size()-1 && tests_[l]>tests_[maxindex])
		maxindex = l;
	int r = 2*i +2;
	if(r<=size-1 && tests_[r]>tests_[maxindex])
		maxindex = r;
	if(i!=maxindex){
		swap(tests_[i],tests_[maxindex]);
		SiftDown(maxindex);
	}
}

int ExtractMax(){
	int result = tests_[0];
	tests_[0] = tests_[tests_.size()-1];
	tests_.resize(tests_.size()-1);
	SiftDown(0);
	return result;
}

void SiftUp(int i){
	int size = tests_.size();
	int parent = (i-1)/2;
	while(i<size && tests_[i]>tests_[parent]){
		swap(tests_[i],tests_[parent]);
		i = parent;
	}
}

void Insert(int p){
	tests_.push_back(p);
	int size = tests_.size();
	SiftUp(size-1);
}



int main(int argc,char** argv){
	setbuf(stdout,NULL);

	int TC;
	int test_case;

	scanf("%d",&TC);
	for(test_case=1;test_case<=TC;test_case++)
	{
		int N;
		int K;
		cin>>N>>K;
		for(int i=0;i<N;++i){
			int j;
			cin>>j;
			tests_.push_back(j);
		}
		sort(tests_.begin(),tests_.end());
		int answer=0;
		for(int i=0;i<K;++i)
			answer += tests_[N-i-1];

		tests_.clear();



		printf("Case #%d\n",test_case);
		cout<<answer<<endl;
	}

	return 0;
}
