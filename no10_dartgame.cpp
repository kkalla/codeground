#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

const double PI = 3.14159265;

int Answer;
vector<int> radiuses_;
int numoftries;
vector<pair<int,int>> darts_;

int scores_[4][6]={
{6,13,4,18,1,20},
{11,14,9,12,5,20},
{11,8,16,7,19,3},
{6,10,15,2,17,3}};

int getQuadrant(pair<int,int> dart){
	if(dart.first>=0 && dart.second>=0)
		return 1;
	if(dart.first>=0 && dart.second<=0)
		return 4;
	if(dart.first<=0 && dart.second>=0)
		return 2;
	if(dart.first<=0 && dart.second<=0)
		return 3;
}

int getAngle(pair<int,int> dart)
{
	double angle;
	int result;
	if(dart.first==0)
		angle=90;
	else
		angle = abs(atan(static_cast<double>(dart.second)/dart.first))
			*180/PI;
	if(angle<9)
		result = 0;
	else if(angle<27)
		result = 1;
	else if(angle<45)
		result = 2;
	else if(angle<63)
		result = 3;
	else if(angle<81)
		result = 4;
	else
		result = 5;

	return result;
}

double getDistance(pair<int,int> dart){
	double distance;
	distance = sqrt(pow(static_cast<double>(dart.first),2)+
			pow(dart.second,2));
	return distance;
}

int isDoubleOrTripleOrOut(double distance){
	int result=1;
	if(distance>radiuses_[1]&&distance<radiuses_[2])
		result = 3;
	else if(distance>radiuses_[3]&&distance<radiuses_[4])
		result = 2;
	else if(distance>radiuses_[4])
		result = 0;
	return result;
}

int getScore(pair<int,int> dart){
	int score;
	int which_quadrant = getQuadrant(dart);
	int angle = getAngle(dart);
	double distance = getDistance(dart);
	if(distance<radiuses_[0])
		score = 50;
	else {
		score = scores_[which_quadrant-1][angle];
	}
	return score*isDoubleOrTripleOrOut(distance);
}

int main(int argc, char** argv){
	freopen("sample_input.txt","r",stdin);
	int T,test_case;
	cin >> T;

	for(test_case=0;test_case<T;test_case++){
		Answer = 0;
		numoftries = 0;
		radiuses_.clear();
		darts_.clear();
		//input data
		for(int i=0;i<5;++i){
			int radius;
			cin>>radius;
			radiuses_.push_back(radius);
		}
		cin>>numoftries;
		for(int i=0;i<numoftries;++i){
			int dartx,darty;
			cin>>dartx>>darty;
			pair<int,int> dart = make_pair(dartx,darty);
			darts_.push_back(dart);
		}

		for(int i=0;i<numoftries;++i){
			int score = getScore(darts_[i]);
			Answer += score;
		}



		cout<<"Case #"<<test_case+1<<endl;
		cout<<Answer<<endl;
	}



	return 0;
}
