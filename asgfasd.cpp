#include <iostream>
class Matrix
{
private:
    int m,n;
    double **data;
public:
    Matrix(int newM=0,int newN=0)
        : n{newN}, m{newM}
    {
        data =new double*[m];
        for (int i = 0;i<m;i++){
            data[i]=new double[n];
            for (int j=0;j<n;j++){
                data[i][j]=0;
            }
        }
    }
    ~Matrix(){
        for (int i = 0; i<m; i++){
            delete data[i];
        }
        delete data;
    }
    void operator= (const Matrix& D);
    Matrix operator+ (const Matrix& D) const;
    Matrix operator- (const Matrix& D) const;
    
    friend std::ostream& operator<<(std::ostream &out, const Matrix &mtr);
    friend std::istream& operator>>(std::istream &in, Matrix &mtr);
    Matrix minor(int r,int c);
    double det();
};

std::ostream& operator<< (std::ostream&out, const Matrix &mtr)
{
    int i,j;
    out<<"Matrix(" << mtr.m << ", " << mtr.n << ')' << std::endl;
    for (i=0;i<mtr.m;i++){
        for (j=0;j<mtr.n;j++){
            out << mtr.data[i][j]<<" ";
        }
        out <<std::endl;
    }
    
    return out;
}

std::istream& operator>> (std::istream &in, Matrix &mtr)
{
    int i,j;
    for (i=0;i<mtr.m;i++){
        for (j=0;j<mtr.n;j++){
            in >> mtr.data[i][j];
        }
    }
    return in;
}
void Matrix::operator= (const Matrix& D){
    for (int i = 0; i<m;i++){
        delete data[i];
    }
    delete data;
    
    m=D.m;
    n=D.n;
    
    data = new double*[m];
    for (int i=0;i<m;i++){
        data[i]=new double[n];
        for (int j=0;j<n;j++){
            data[i][j]=D.data[i][j];
        }
    }
}
Matrix Matrix::operator+ (const Matrix& D) const
{
    if (m!= D.m||n!=D.n){
        std::cout<<"Сложение матриц невозможно";
        exit(1);
    }
    Matrix A(m,n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            A.data[i][j]=data[i][j]+D.data[i][j];
        }
    }
    return A;
}
Matrix Matrix::minor(int r, int c){
    Matrix A(m-1,n-1);
    int i,j,i1,j1;
    for (i=0,i1=0;i<m;i++)
        if (i!=r){
            for (j=0,j1=0;j<n;j++)
                if (j!=c){
                    A.data[i1][j1]=data[i][j];
                    j1++;
                }
            i1++;
        }
    return A;
}
double Matrix::det(){
    if (m!=n) return 0;
    if (m==1) return data[0][0];
    int zn=1;
    Matrix A;
    double res=0;
    for (int i=0;i<m;i++){
        A.minor(0,i);
        std::cout<<A;
        res+=data[0][i]*zn*A.det();
        zn=-zn;
    }
    return res;
}

int main()
{
    Matrix mtr(3,3), mt(3,3), mr;
    std::cout <<mtr<<'\n';
    std::cin >> mtr;
    std::cout<<mtr<<'\n';
    //std::cout<<mt<<'\n';
    mt=mtr;
    //std::cout<<mt<<'\n';
    //std::cout<<mr<<'\n';
    //mr=mtr+mt;
    //std::cout<<mr<<'\n';
    //mr=mt.minor(1,1);
    //std::cout<<mr<<'\n';
    double z = mt.det();
    std::cout<<z<<std::endl;
    return 0;
}