#include <iostream>
#include <vector>
#include <malloc.h> 
std::ostream& operator<<(std::ostream &out,std::vector<int> &src){
    if (!src.empty()){
        for (std::vector<int>::iterator i = src.begin(); i != src.end() ; ++i) {
            out<<*i<<' ';
        }
        out<<std::endl;
    }else {out<<"VECTOR should not be empty"<<std::endl;}
    return out;
}
void print(int* a){
    for (int i = 0; i < _msize(a)/4; ++i) {
        std::cout<<a[i]<<' ';
    }
    std::cout<<std::endl;
}
struct make_apart{
    make_apart(int l1,int l2){
        this->l1=l1;
        this->l2=l2;
        this->Dfirst=new int[l1];
        this->Dsecond=new int[l2];
    }
    make_apart(){
    };
    std::vector<int> first;
    std::vector<int> second;
    int l1,l2;
    int* Dfirst=NULL;
    int* Dsecond=NULL;
};
void x_change(int* a,int* b){
    int c=*a;
    *a=*b;
    *b=c;
}
make_apart to_apart(const std::vector<int> &c){
    make_apart d;
    for (unsigned int i = 0; i < c.size()/2 ; ++i) {
        d.first.push_back(c[i]);
    }
    for (unsigned int j = c.size()/2; j < c.size(); ++j) {
        d.second.push_back(c[j]);
    }
    return d;
}
void fix_arrange(std::vector<int>* a){
    for (unsigned int i = 0; i < a->size()-1 ; ++i) {
        for (unsigned int j = i+1; j < a->size(); ++j) {
            if (a->at(j) < a->at(i)){
                x_change(&(a->at(i)),&(a->at(j)));
            }
        }
    }
}
std::vector<int> two_in_one(std::vector<int> a,const std::vector<int> &b){
    std::vector<int> c;
    c.reserve(a.size()+b.size()+10);
    for (int i = 0; i < b.size() ; ++i) {
        while ( (!a.empty()) && (a[0]<b[i]) ){
            c.push_back(a[0]);
            a.erase(a.begin());
        }
        c.push_back(b[i]);
    }
    for (std::vector<int>::iterator j = a.begin(); j !=a.end() ; ++j) {
        c.push_back(*j);
    }
    return  c;
}
make_apart to_apart(int* c){
    int len=_msize(c)/4; 
    make_apart d(len/2,len-len/2);
    for (int i = 0; i < len/2 ; ++i) {
        d.Dfirst[i]=c[i];
    }
    for (int i = len/2; i < len ; ++i) {
        d.Dsecond[i-len/2]=c[i];
    }
    return d;
}
void fix_arrange(int* &c){
    int len=_msize(c)/4;
    for (int i = 0; i < len-1; ++i) {
        for (int j = i+1; j < len; ++j) {
            if(c[j] < c[i]){
                x_change(&c[j],&c[i]);
            }
        }
    }
}
int* two_in_one(int* &a,int* &b){
    int len_a=_msize(a)/4;
    int len_b=_msize(b)/4;
    int len=len_a+len_b;
    int* c = new int[len];
    int a_index=0;
    int c_index=0;
    for (int i = 0; i < len_b; ++i) {
        while ( (a_index!=len_a) && (a[a_index]<b[i]) ){
            c[c_index++]=a[a_index++];
        }
        c[c_index++]=b[i];
    }
    for (int j = a_index; j < len_a ; ++j) {
        c[c_index++]=a[a_index++];
    }
    return c;
}
int main(){
    std::vector<int> a{11,8,2,6,3};
    auto apart=to_apart(a);
    fix_arrange(&apart.first);
    fix_arrange(&apart.second);
    auto final=two_in_one(apart.first,apart.second);
    std::cout<<final;
    int* b= new int[5]{11,8,2,6,3};
    auto Apart=to_apart(b);
    fix_arrange(Apart.Dfirst);
    fix_arrange(Apart.Dsecond);
    auto Final=two_in_one(Apart.Dfirst,Apart.Dsecond);
    print(Final);
    return 0;
}