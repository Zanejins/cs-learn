#include<iostream>

using namespace std;

const double * f1(const double ar[],int n);
const double * f2(const double [],int);
const double * f3(const double *,int);

using namespace std;


int main() {
    double av[3]={1112.3,1542.6,2227.9};

    const double * (*p1) (const double *,int) = f1;
    auto p2 = f2;

    cout<<"Using pointers to function: "<<endl;
    cout<<" Address Value\n";
    cout<< (*p1)(av,3)<<" : "<< *(*p1)(av,3)<<endl;
    cout<< p2(av,3)<<" : "<< *p2(av,3)<<endl;

    const double *(*pa[3])(const double *,int) = {f1,f2,f3};
    cout<<"\nUsing an array of pointers to functions:"<<endl;
    cout<<"Address Value"<<endl;

    for(int i=0;i<3;i++) {
        cout<<pa[i](av,3)<<" : " << *pa[i](av,3)<<endl;
    }

    cout <<"Using a pointer to a pointer to a fuinction:"<<endl;
    cout<<"Address Value"<<endl;
    auto pb=pa; //pb is a pointer to the first element of pa;
    //const double * (**pb) (const double *.int) =pa;
    for(int i=0;i<3;i++) {
        cout<<pb[i](av,3)<<" : " << *pb[i](av,3)<<endl;
    }

    cout<<"Using a pointer to an array of function pointers:"<<endl;
    cout<<"Address Value\n";
    auto pc = &pa;
    // const double * (* (*pa)[3]) (const double *,int) = &pa;
    cout << (*pc)[0](av,3) <<" : "<< *(*pc)[0](av,3) <<endl;
    
    const double *(*(*pd)[3])(const double *,int) = &pa;

    const double * pdb = (*pd)[1](av,3);
    cout<<pdb<<" :" <<*pdb<<endl;
    //alternation notion
    cout<<(*(*pd)[1])(av,3)<<" : "<<*(*(*pd)[1])(av,3)<<endl;
    return 0;
}

const double * f1(const double * ar,int n){
    return ar;
} 

const double * f2(const double ar[],int n) {
    return ar+1;
}

const double * f3(const double ar[],int n) {
    return ar+3;
}