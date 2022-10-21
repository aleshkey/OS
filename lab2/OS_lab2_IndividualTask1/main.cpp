#include <iostream>
#include <thread>
#include <cmath>
#include <fstream>
#include <chrono>

using namespace std;

long long getFactorial(long int x){
    long long res=1;
    for (long int i = 1; i <= x; i++) {
        res*=i;
    }
    return res;
}


long double getTerm(long int x, long int n){
    cout<<"tread id: "<<this_thread::get_id()<< endl;
    long double res = pow(-1,n-1)*pow(x, 2*n-1)/ getFactorial(2*n-1);
    cout<<res<<endl;
    return res;
}

int main() {
    ofstream fout("result.txt");
    fout.open("result.txt", ios::app);
    fout.clear();
    int k, n, N;
    cout<<"введите К\n";
    cin>>k;
    cout<<"введите N\n";
    cin>>N;
    cout<<"введите n\n";
    cin>>n;
    for(int i=0; i<k; i++) {
        long double x = 2*M_PI*i/N;
        while (x>=2*M_PI){
            x-=2*M_PI;
        }
        long double sum = 0;
        for (int j = 0; j < n; j++){
            thread th([&sum, &j, &x] () {
                sum = sum + getTerm(x, j);
            });
            th.detach();
        }
        this_thread::sleep_for(chrono::milliseconds(100));
        fout<<sum<<endl;
    }
    fout.close();
    return 0;
}
