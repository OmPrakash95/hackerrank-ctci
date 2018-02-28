#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

float findMedian(int k, float m, priority_queue <int, vector<int>, less<int> > &l, priority_queue <int, vector<int>, greater<int> > &r){

	if(l.size() > r.size()){
		if(k<(int)m){
			r.push(l.top());
			l.pop();
			l.push(k);
		}
		else{
			r.push(k);
		}
		m = (float)((l.top()+r.top())/2.0);
		return m;			
	}
	if(l.size() == r.size()){
		if(k<(int)m){
			l.push(k);
			m = (float)l.top();	
		}
		else{
			r.push(k);
			m = (float)r.top();
		}
		return m;			
	}
	if(l.size() < r.size()){
		if((float)k < m){
			l.push(k);
		}
		else{
			l.push(r.top());
			r.pop();
			r.push(k);
		}
		m = (float)((l.top() + r.top())/2.0);
		return m;
	}
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<float> med(n);

    priority_queue <int, vector<int>, greater<int> > right;
    priority_queue <int, vector<int>, less<int> > left;
    float m = 0.0;

    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
       m = findMedian(a[a_i], m, left, right);
       med[a_i] = m;
    }

    for(int a_i = 0;a_i < n;a_i++){
    	cout<<std::fixed<<setprecision(1)<<med[a_i]<<endl;
    }    

    return 0;
}
