#include <iostream>

using namespace std;

class mString{
    private:
    char *st;
    
    public:
    mString(){
        st=NULL;
    }
    void test(){
        st=new char(10);
        char c='a';
        for (int i=0;i<10;i++) st[i]=c++;
        st[9]='\0';
        cout<<st<<endl;
    }
    ~mString(){
        if (st)(delete st);
    }
    void operator= (const mString &s);
    void operator= (const char* s);
    mString operator+ (const mString &s) const;
    mString operator+ (const char* s) const;
    mString substr (int r, int c);
    mString find ()
    friend std::ostream& operator<< (std::ostream &out, const mString &s);
    friend std::istream& operator>> (std::istream &in, mString &s);
    friend bool operator== (const mString &s1, const mString &s2);
};
std::ostream& operator<<(std::ostream &out, const mString &s){
    cout<<s.st;
    return out;
}
std::istream& operator>>(std::istream &in, mString &s){
    char buf[10000],t;
    int i,k=0;
    t=in.get();
    while ((int)(t)!=10){
        buf[k++]=t;
        t=in.get();
    }
    if (s.st) delete s.st;
    s.st = new char[k+1];
    for (i=0;i<k;i++) s.st[i]=buf[i];
    s.st[i]='\0';
    return in;
}
void mString::operator= (const mString &s){
    if(st) delete st;
    int i, k=0;
    while(s.st[k++]);
    st=new char[k+1];
    for (i=0;i<k;i++) st[i]=s.st[i];
    st[i]='\0';
}
void mString::operator= (const char* s){
    if(st) delete st;
    int i, k=0;
    while(s[k++]);
    st=new char[k+1];
    for (i=0;i<k;i++) st[i]=s[i];
    st[i]='\0';
}
mString mString::operator+ (const mString& s) const{
    mString res;
    int i, k=0,k1=0,k2=0;
    while(st[k1++]);
    k1--;
    while(st[k2++]);
    k2--;
    res.st=new char[k1+k2+1];
    for (i=0;i<k1;i++) res.st[k++]=st[i];
    for (i=0;i<k2;i++) res.st[k++]=s.st[i];
    
    res.st[k]='\0';
    return res;
    
}
mString mString::operator+ (const char* s) const{
    mString res;
    int i,k=0,k1=0,k2=0;
    while(st[k1++]);
    k1--;
    while(st[k2++]);
    k2--;
    res.st=new char[k1+k2+1];
    for (i=0;i<k1;i++) res.st[k++]=st[i];
    for (i=0;i<k2;i++) res.st[k++]=s[i];
    
    res.st[k]='\0';
    return res;
}
mString mString::substr (int r, int c){
    int i,k=c;
    for (i=r;i<k;i++) cout<<st[i];
}
bool operator== (const mString &s1, const mString &s2){
    int i,k=0,k1=0,k2=0;
    while(s1.st[k1++]);
    k1--;
    while(s2.st[k2++]);
    k2--;
    if(k1!=k2) return 0;
    for (i=0;i<k1;i++) if(s1.st[i]!=s2.st[i]) return 0;
    return 1;
}

int main()
{
    //char c[100];
    //cin>>c;
    //cout<<c<<endl;
    mString s,p,t;
    //s.test();
    //cout<<s<<endl;
    cin>>s;
    //cout<<s<<endl;
    p=s;
    //cout<<p<<endl;
    cin>>s;
    cout<<s<<endl;
    //cout<<p<<endl;
    //t=p+s;
    //cout<<t<<endl;
    //t="asdqwrfqsfqwqwdq sw qswdqs";
    //cout<<t<<endl;
    //t=s+"asdqewfadfq dqws dqs";
    //cout<<t<<endl;
    //s.substr(0,5);
    p==s;
    
    return 0;
}