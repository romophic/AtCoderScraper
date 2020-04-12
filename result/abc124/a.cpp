#include <iostream>
using namespace std;
int main(){
	
	int a,b,ans=0;
	cin>>a>>b;
	if(a<b){
		ans+=b;
		b--;
	}else{
		ans+=a;
		a--;
	}

	if(a<b){
		ans+=b;
		b--;
	}else{
		ans+=a;
		a--;
	}
	cout<<ans<<endl;
	
	return 0;
}

