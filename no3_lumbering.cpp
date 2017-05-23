#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int naive_answer(int n,vector<int> trees){
	int laser_height;
	int sum=0;
	int tree;
	for(int i=0;i<n;++i){
		cin>>tree;
		trees.push_back(tree);
	}
	for(int i=0;i<n;++i){
		cin>>laser_height;
		for(int j=0;j<n;++j){
			if(trees[j]>laser_height){
				sum += trees[j]-laser_height;
				trees[j]=laser_height;
			}
		}
		for(int j=0;j<n;++j)
			trees[j] += 1;
	}

	return sum;
}

long long fast_answer(vector<int> trees,vector<int> lasers){
	int total_num = trees.size();
	long long result=0;
	int min_laser = INT_MAX;

	for(int i=0;i<total_num;++i)
		min_laser = min(min_laser,lasers[i]-i);
	for(int i=0;i<total_num;++i){
		int max_cut = max(trees[i]-min_laser,0);
		result += max_cut;
	}

	return result;

}


int main(int argc, char** argv){
	//freopen("sample_input.txt","r",stdin);
	setbuf(stdout, NULL);

	int T;
	int test_case;
	vector<int> trees;
	vector<int> lasers;

	scanf("%d",&T);
	for(test_case = 1;test_case <= T; test_case++){
		int n;
		cin >> n;
		int tree_height;
		int laser_height;
		for(int i=0;i<n;++i){
			cin>>tree_height;
			trees.push_back(tree_height);
		}
		for(int i=0;i<n;++i){
			cin>>laser_height;
			lasers.push_back(laser_height);
		}

		//int result = naive_answer(n,trees);
		int result = fast_answer(trees,lasers);

		trees.clear();
		lasers.clear();


		printf("Case #%d\n",test_case);
		printf("%d\n",result);
	}

	return 0;
}
