#include<iostream>
#include<sycl/sycl.hpp>
using namespace sycl;

const std::string secret{
    "Ifmmp-!xpsme\"\012J(n!tpssz-!Ebwf/!)"
    "J(n!bgsbje!J!dbo(u!ep!uibu/!.!IBM\01"};

const auto sz=secret.size();

int main()
{
    queue q;

    char *res=malloc_shared<char>(sz,q);
    std::memcpy(res,secret.data(),sz);

    q.parallel_for(sz,[=](auto& i) {
        res[i]-=1;
    }).wait();

    std::cout<<res<<"\n";
    free(res,q);
    return 0;
}