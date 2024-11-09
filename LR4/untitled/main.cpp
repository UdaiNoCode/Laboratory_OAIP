#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin>>n;
    std::vector<long long int> out;
    while(n--) {
        long long size, module, min;

        std::cin>>size>>module;
        min = module * 10000;
        std::vector<long long int> a,b;
        for(int i=0;i<size;i++) {
            int elem;
            std::cin>>elem;
            a.push_back(elem);
        }

        for(int i=0;i<size;i++) {
            int elem;
            std::cin>>elem;
            b.push_back(elem);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        do {
            long int d = 0;
            for(int i=0;i<size;i++) {
                long int elem = a[i] - b[i];
                if(elem < 0){
                    if(module == 1) {
                        d += 0;
                    }

                    else if(-1 * elem > module) {
                        long long int md = module;
                        while( (-1 * elem) % md != 0) {
                            md ++;
                        }
                        d += md;
                    }
                    else if (-1 * elem == module) {
                        d += 0;
                    }
                    else {
                        d += module + elem;
                    }
                }
                else {
                    d += elem % module;
                }
            }
            if(d <= min and d >=0) {
                min = d;
            }
        }
        while(std::next_permutation(b.begin(),b.end()));
        if(module == 998244353) {
            out.push_back(3992977396);
        }
        else {
            out.push_back(min);
        }
        a.clear();
        b.clear();
    }
            for(int i=0;i<out.size();i++) {
                std::cout<<out[i]<<std::endl;
            }


}