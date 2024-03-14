#include <iostream>
#include <iomanip>
using namespace std;

class element{
public:
    int data;
    element(int c){
        data = c;
    }

    static void print(element (*p)[3])
    {
        for(int i = 0; i < 3;i++)
	{
         cout<<endl;
		for(int j = 0;j < 3;j++){
            cout.width(3);
			cout<<p[i][j].data<<" ";
	    }
    }
     cout<<endl;}

    static void transport(element (*p)[3]){
        int a[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                  a[j][i]  = p[i][j].data;
            }
        }
        for(int i = 0; i < 3;i++){
         cout<<endl;
		for(int j = 0;j < 3;j++){
            cout.width(3);
			cout<<a[i][j]<<" ";}
        }
        cout<<endl;
    }

    static void dot(element (*a)[3],element (*b)[3]){
        int p[3][3]={0};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    p[i][j]+=a[i][k].data * b[k][j].data;
                }
            }
        }
        for(int i = 0; i < 3;i++){
         cout<<endl;
		for(int j = 0;j < 3;j++){
            cout.width(5);
			cout<<p[i][j]<<" ";}
        }
        cout<<endl;
    }

    static void kroneckor(element (*a)[3],element (*b)[3]){
        int p[9][9]={0};
        for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    p[i*3+k][j*3+l] = a[i][j].data * b[k][l].data;}}}}
        for(int m = 0; m < 9;m++){
         cout<<endl;
		for(int n = 0;n < 9;n++){
            cout.width(5);
			cout<<p[m][n]<<" "<<" ";}
        }
        cout<<endl;
    }
};

