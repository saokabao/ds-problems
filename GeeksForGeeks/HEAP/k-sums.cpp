#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef set<ll> si;
typedef map<string,ll> msi;


    #define INF 20000000
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define sz size()
    #define ln length()
    #define rep(i,n) for(ll i=0;i<n;i++)
    #define fu(i,a,n) for(ll i=a;i<=n;i++)
    #define fd(i,n,a) for(ll i=n;i>=a;i--)
    #define all(a)  a.begin(),a.end()
    #define pl(a) cout<<a
    #define nl cout<<endl
    #define present(container,element) container.find(element)!=container.end()
    #define cpresent(container,element) find(all(container),element)!=container.end()


 ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}



struct node
{
    int sum;
    int Ai,Bi;

    node (int a, int b, int c)
    {
        sum=a;
        Ai=b;
        Bi = c;
    }
};

struct comp
{
    bool  operator()(node *a, node *b)
    {
        return a->sum < b->sum;
    }
};

vector<int> solve(vector<int> &A, vector<int> &B) {
    priority_queue<node*, vector<node*>, comp> PQ;
    set<pair<int,int>> cont;


    int n = A.size();
    vector<int> ans;
    if (n==0) return ans;


    sort(A.begin(),  A.end());
    sort(B.begin(), B.end());

    cont.insert(make_pair(n-1,n-1));
    PQ.push(new node(A[n-1]+B[n-1], n-1,n-1));

    int x =0;


    while(x<n)
    {
	    cout<<"x: "<<x<<"\n";
        node *X = PQ.top();
        PQ.pop();
        ans.push_back(X->sum);

	int i = X->Ai;
	int j = X->Bi;

        pair<int , int> P1 (i-1,j), P2(i,j-1);

	
        if (i-1>=0 && cont.find(P1) == cont.end())
        {
            cont.insert(P1);
            PQ.push(new node (A[P1.first] + B[P1.second], P1.first, P1.second));
        }
	cout<<"pushed p1\n";

        if (j-1>=0 && cont.find(P2) == cont.end())
        {
	    cout<< " j-1 : "<< j-1<<"\n";	
            cont.insert(P2);
            PQ.push(new node (A[P2.first] + B[P2.second], P2.first, P2.second));
        }
        x++;
    }
     return ans;

}


int main()
{
    vector<int> A = {1,4,2,3};
    vector<int> B = {2,5,1,6};

    vector<int> C;
    C  = solve(A,B);

    for(int i=0;i<C.size();i++)
    {
	    cout<<"sum[i]: "<<C[i]<<"\n";
    }
    return 0;
}

