#include <iostream>
using namespace std;
template <typename T>
class Compare{
private:
	T p[6];
public:
	Compare(T input_data[6]) {
        for (int i = 0; i < 6; ++i) {
            p[i] = input_data[i];
        }
    }

	T max(){
		T max1=p[0];
			for(int i=1;i<6;i++){
				if(max1<p[i]){
					max1=p[i];
			}
		}
		return max1;
	}

	T min(){
		T min1=p[0];
		for(int i=1;i<6;i++){
			if(min1>p[i]){
				min1=p[i];
			}
		}
		return min1;
	}

	T avg(){
		T sum = 0;
        for(int i=0;i<6;i++){
            sum+=p[i];
        }
        return sum/6;
    }

	void AscendSort(){
	T t;
	for(int i=0;i<6;i++){
		for(int j=0;j<5-i;j++){
			if(p[j+1]<p[j]){
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
			}	
		}
	}
	for(int m=0;m<6;m++){
		cout<<p[m]<<"  ";
	}
	cout<<endl;
}
	
	void DescendSort(){
		T t;
		for(int i=0;i<6;i++){
			for(int j=0;j<5-i;j++){
				if(p[j+1]>p[j]){
					t=p[j+1];
					p[j+1]=p[j];
					p[j]=t;
				}	
			}
		}
		for(int m=0;m<6;m++){
			cout<<p[m]<<"  ";
		}
		cout<<endl;
}

    void Check_info(){
        cout<<"Max = "<<max()<<endl;
        cout<<"Min = "<<min()<<endl;
        cout<<"Average = "<<avg()<<endl;
        AscendSort();
        DescendSort();
    }
}; 

template <>
class Compare<char>{
private:
	char p[6];
public:
	Compare(char input_data[6]) {
        for (int i = 0; i < 6; ++i) {
            p[i] = input_data[i];
        }
    }

	char max(){
		char max1=p[0];
			for(int i=1;i<6;i++){
				if(max1<p[i]){
					max1=p[i];
			}
		}
		return max1;
	}

	char min(){
		char min1=p[0];
		for(int i=1;i<6;i++){
			if(min1>p[i]){
				min1=p[i];
			}
		}
		return min1;
	}

	char avg(){
		char sum = '0';
        for(int i=0;i<6;i++){
            sum+=p[i];
        }
        return sum/'6';
    }

	void AscendSort(){
	char t;
	for(int i=0;i<6;i++){
		for(int j=0;j<5-i;j++){
			if(p[j+1]<p[j]){
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
			}	
		}
	}
	for(int m=0;m<6;m++){
		cout<<p[m]<<"  ";
	}
	cout<<endl;
}
	
	void DescendSort(){
		char t;
		for(int i=0;i<6;i++){
			for(int j=0;j<5-i;j++){
				if(p[j+1]>p[j]){
					t=p[j+1];
					p[j+1]=p[j];
					p[j]=t;
				}	
			}
		}
		for(int m=0;m<6;m++){
			cout<<p[m]<<"  ";
		}
		cout<<endl;
}

    void Check_info(){
        cout<<"Max = "<<max()<<endl;
        cout<<"Min = "<<min()<<endl;
        cout<<"Average = "<<avg()<<endl;
        AscendSort();
        DescendSort();
    }
}; 

