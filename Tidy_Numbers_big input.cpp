//============================================================================
// Name        : Tidy_Numbers_version3.cpp
// Author      : 
// Version     :3
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//this answer works on detecting the digit that the change should start from
//then construct the new number then check
//8/4/2017
//accepted
//
//============================================================================

#include <iostream>
#include <string>
using namespace std;
bool isTedy(unsigned long long x){
	string s=to_string(x);
	int count=0;
	int len=s.length();
	for(int i=1;i<len;i++){
		if(s[i-1]<=s[i]){
			count++;
		}
		else {
			return false;
		}
		if(count==len){
			return true;
		}
	}
}
 /*** *_* ****************** *_******/
int thestartindex(unsigned long long n){
	string s =to_string(n);
	int numlength=s.length();
	for(int i=1;i<numlength;i++){
		if(s[i-1]>s[i]){
			return i-1;
		}
	}
}
/**************************/
unsigned long long reconstruct(unsigned long long n){
	unsigned long long n2=n;
	string s=to_string(n);
	string result;
	int numlength=s.length();
	int arr[numlength];
	int startindex=thestartindex(n2);
for(int i=numlength-1;i>=0;i--)
    {
	arr[i]=n%10;
	n=n/10;
    }
arr[startindex]=arr[startindex]-1;
for(int i=startindex+1;i<numlength;i++){
	arr[i]=9;
}
for(int i=0;i<numlength;i++){
	result+=arr[i]+'0';
}
return stoull(result);


}
/********************  *_*  ******************/



int main() {
   freopen("B-large.in","rt",stdin);
   freopen("output.txt","wt",stdout);
	 int t;
	 int cases=0;
	 cin>>t;
	 while(t--){
	 	++cases;
		 unsigned long long n;
		 cin>>n;
		 while(!isTedy(n)){
			  n=reconstruct(n);
			 }
			 cout<<"Case #"<<cases<<": "<<n<<endl;
		 }




	return 0;
}

