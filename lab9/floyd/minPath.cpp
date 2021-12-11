#include<iostream>
using namespace std;
const int INF = 1e9;
int main(){
    int n;cin>>n;
    int d[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>d[i][j];

    
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    bool ok = true;
    for (int i=0; i<n; ++i)
    	for (int j=0; j<n; ++j)
	    	for (int t=0; t<n; ++t)
		    	if (d[i][t] < INF && d[t][t] < 0 && d[t][j] < INF)
			    	ok = false;
    if(!ok){
        cout<<-1;
        return 0;
    }
    int mn = INF;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(mn>d[i][j]&&d[i][j]!=0)
                mn = d[i][j];
    cout<<mn;
    return 0;
}