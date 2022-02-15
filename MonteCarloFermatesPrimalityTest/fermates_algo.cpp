#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int fermatesAlgo(long long int a,long long int n,long long int p)
{
    long long int result=1;
    a=a%p;
    while (n>0)
    {
        if(n & 1)
            result=(result*a)%p;
        n=n/2;
        a=(a*a)%p;
    }
    return result;
}

long long int gcd(long long int num,long long int a)
{
    if(num<a)
        return gcd(a,num);
    else if(num%a == 0)
        return a;

    else 
        return gcd(a,num%a);
}

bool isBool(long long int num,long long int k)
{
    if(num<=1 || num==4)
        return false;
    else if(num<=3)
        return true;

    while (k>0)
    {
        long long int a=2+rand()%(num-4);
        
        if(gcd(num,a) != 1)
            return false;

        if(fermatesAlgo(a,num-1,num) != 1)
            return false;

        k--;
    }
    return true;
}
int main()
{
    bool result;

    // result=isBool(5,5);
    // result ? cout<<"5 no is  prime     :"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;

    // result=isBool(97,5);
    // result ? cout<<"97 no is  prime    :"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;

    // result=isBool(199,5);
    // result ? cout<<"199 no is  prime   :"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;

    // result=isBool(599,5);
    // result ? cout<<"599 no is  prime   :"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;
    
    // result=isBool(997,5);
    // result ? cout<<"997 no is  prime   :"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;
    
    // result=isBool(5591,5);
    // result ? cout<<"5591 no is  prime  :"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;
    
    // result=isBool(99991,5);
    // result ? cout<<"99991 no is  prime :"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;
    
    // result=isBool(995699,5);
    // result ? cout<<"995699 no is  prime:"<<"true"<<endl:cout<<"5 no is  prime : "<<"false"<<endl;


    // result=isBool(9,5);
    // result ? cout<<"9 no is  prime     :"<<"true"<<endl:cout<<"9 no is  prime     :"<<"false"<<endl;

    // result=isBool(27,5);
    // result ? cout<<"27 no is  prime    :"<<"true"<<endl:cout<<"27 no is  prime    :"<<"false"<<endl;

    // result=isBool(297,5);
    // result ? cout<<"297 no is  prime   :"<<"true"<<endl:cout<<"297 no is  prime   :"<<"false"<<endl;

    // result=isBool(597,5);
    // result ? cout<<"597 no is  prime   :"<<"true"<<endl:cout<<"597 no is  prime   :"<<"false"<<endl;
    
    // result=isBool(993,5);
    // result ? cout<<"993 no is  prime   :"<<"true"<<endl:cout<<"993 no is  prime   :"<<"false"<<endl;
    
    // result=isBool(5597,5);
    // result ? cout<<"5597 no is  prime  :"<<"true"<<endl:cout<<"5597 no is  prime  :"<<"false"<<endl;
    
    // result=isBool(99999,5);
    // result ? cout<<"99999 no is  prime :"<<"true"<<endl:cout<<"99999 no is  prime :"<<"false"<<endl;
    
    // result=isBool(995693,5);
    // result ? cout<<"995693 no is  prime:"<<"true"<<endl:cout<<"995693 no is  prime:"<<"false"<<endl;
    
    return 0;
}