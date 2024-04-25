//Creator: Amna(23k-0066)

#include<iostream>
#include <string>
using namespace std;

class Logo{
private:
    string logo;
public:
    Logo(string logo) : logo(logo)  {}
    void display(){
        cout << "Logo: " << logo << endl;
    }
};

class Server{
private:
    string address;
    int port;
public:
    Server(int port, string addr) : port(port), address(addr) {}
    void display(){
        cout << "Port: " << port << endl;
        cout << "IP Adress: " << address << endl;
    }
};

class Platform{
private:
    Logo logo;
    Server server;
    string name;
public:
    Platform(string platform_logo, string platform_address, int port, string platform_name) : logo(platform_logo), server(port, platform_address), name(platform_name) {}
    void display(){
        cout << "\nName: " << name << endl;
        logo.display();
        server.display();
    }

    friend void changeLogo(Platform& platform, const Logo& newLogo);
};

void changeLogo(Platform& platform, const Logo& newLogo){
    platform.logo = newLogo;
}

int main(){
    cout << "\nProgrammer: Amna(23K-0066)" << endl << endl;
    Platform twitter("blue bird", "172.14.1.2.4", 344, "Twitter");
    cout << "\nBefore changing the logo:" ;
    twitter.display();
    cout << "\nAfter changing the logo:" ;
    changeLogo(twitter, Logo("X"));
    twitter.display();

}
