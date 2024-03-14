#include "charlie6.h"

int main() {
    Cart cart;
    Product camera1("Sony相机", 15999),camera2("GoPro相机",5999),camera3("Canon相机",12999);
    Product lipstick1("HERMES口红", 1000),lipstick2("CHANEL口红", 1200),lipstick3("LANCOME口红", 999);
    Product mooncake1("杏仁月饼", 50),mooncake2("榴莲月饼", 100),mooncake3("菠萝月饼", 80);
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

    cout<<"购物车:"<<endl<<endl;
    cart.listProducts();
    cout <<endl<< "总价: " << cart.totalCost() << endl;
    cout << "最贵的商品价格: " << cart.maxPrice() << endl;
    system("pause");
    return 0;
}
