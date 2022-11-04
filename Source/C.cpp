#include<iostream>
#include <unordered_map>
using namespace std;

// recrusion function
float recursion(float r, float s,float m,float N,std::unordered_map <std::string,float> &map){
    string rstr=std::to_string((int)r);
    string sstr=std::to_string((int)s);
    string mstr=std::to_string((int)m);

    if (map.find(rstr+","+sstr+","+mstr) != map.end())
        return map[rstr+","+sstr+","+mstr];
    // If m==0, that means we cannot take any more items, so just return 0
    if (m==0){
        map[rstr+","+sstr+","+mstr]=0;
        return 0;
    }
        
    
    // As we know, if it is the last item(the N-th item), you can just take this one
    // SO, return the value of the last item, N+1-s
    if (r==N){
        map[rstr+","+sstr+","+mstr]=N+1-s;
        return N+1-s;
    }
       
    
    // Calculate the accept situation
    float Vrs=N+1-(N+1)/(r+1)*s;
    float acceptadd=0;
    for(int i=1;i<=r+1;i++)
        acceptadd=acceptadd+recursion(r+1,i,m-1,N,map)/(r+1);
    float accept=Vrs+acceptadd;

    // Calculate the reject situation
    float reject=0;
    for(int i=1;i<=r+1;i++)
        reject=reject+recursion(r+1,i,m,N,map)/(r+1);

    // Return the max{accept,reject}
    map[rstr+","+sstr+","+mstr]=max(accept,reject);
    return max(accept,reject);
}

int main(){
    float m,N;
    std::unordered_map <string,float> map;
    while (cin>>m>>N) 
    {
        // Use a map to record the V(r,s)
        std::unordered_map <std::string,float> map;
        cout<<recursion(1,1,m,N,map)<<endl; //Get into the recursion, output the answer 
    }
    return 0;
}

