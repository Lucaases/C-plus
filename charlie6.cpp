#include "charlie6.h"

int main() {
    Cart cart;
    Product camera1("Sony���", 15999),camera2("GoPro���",5999),camera3("Canon���",12999);
    Product lipstick1("HERMES�ں�", 1000),lipstick2("CHANEL�ں�", 1200),lipstick3("LANCOME�ں�", 999);
    Product mooncake1("�����±�", 50),mooncake2("�����±�", 100),mooncake3("�����±�", 80);
    Product cellphone1("Mate 60 pro", 8999),cellphone2("iPhone 15 Pro Max", 10999),cellphone3("OPPO Find x6", 5999);

    cart.addProduct(&camera1);
    cart.addProduct(&camera2);
    cart.addProduct(&camera3);
    cart.addProduct(&lipstick1);
    cart.addProduct(&lipstick2);
    cart.addProduct(&lipstick3);
    cart.addProduct(&mooncake1);
    cart.addProduct(&mooncake2);
    cart.addProduct(&mooncake3);
    cart.addProduct(&cellphone1);
    cart.addProduct(&cellphone2);
    cart.addProduct(&cellphone3);

    cout<<"���ﳵ:"<<endl<<endl;
    cart.listProducts();
    cout <<endl<< "�ܼ�: " << cart.totalCost() << endl;
    cout << "������Ʒ�۸�: " << cart.maxPrice() << endl;
    system("pause");
    return 0;
}
