#include <iostream>
#include <vector>

using namespace std;

const int CURRENT_HOUR = 8;

class Restaurant {
public:
    string name, location;
    vector<string> menu;
    vector<float> prices;
    static int coupons_redeemed_count;
    string restaurant_code;

    vector<int> order; // stores indices of purchased items
    float total;

    Restaurant(string name, string location, string code, vector<string> menu, vector<float> prices) 
    : name(name), location(location), restaurant_code(code), menu(menu), prices(prices), total(0)  {}

    void display_menu() {
        for (int i = 0; i < menu.size(); i++)
            cout << "[" << i << "]: " <<  menu[i] << " - $" << prices[i] << endl; 
    }

    void generate_bill() {
        for (int i : order) {
            cout << "[" << i << "]: " <<  menu[i] << " - $" << prices[i] << endl;
            total += prices[i];
        }

        cout << "Total: $" << total << endl;
    }

    void apply_discount() {
        int count = 0;
        for (int i : order) {
            for (int j : order)
                if (i == j) count++;

            if (count >= 2) {
                cout << "Discounted: $" << total - prices[i] << endl;
                return;
            }
        }
    }
};

int Restaurant::coupons_redeemed_count = 0;

class BOGOCoupon {
public:
    string coupon_code, restaurant_code;
    int valid_from, valid_until;

    BOGOCoupon(string c_code, string res_code, int from, int until)
    : coupon_code(c_code), restaurant_code(res_code), valid_until(until), valid_from(from) {}

    bool is_valid(string res_code) {
        return (res_code != restaurant_code && CURRENT_HOUR >= valid_from && CURRENT_HOUR <= valid_until) ? false : true;
    }
};

class User {
public:
    string name, mobile_number;
    int age;
    vector<BOGOCoupon> coupons_list, redeemed_coupons_list;

    User(string name, string phone, int age) : name(name), mobile_number(phone), age(age) {}

    void accumulate_coupon(BOGOCoupon coupon) { coupons_list.push_back(coupon); }

    bool has_valid_coupon(string res_code) {
        for (BOGOCoupon coupon : coupons_list)
            if (!is_redeemed(coupon) && coupon.is_valid(res_code)) return true;
        return false;
    }

    bool redeem_coupon(string res_code, string coupon_code) {
        for (auto it = coupons_list.begin(); it != coupons_list.end(); ++it) {
            if (it->is_valid(res_code) && it->coupon_code == coupon_code) {
                redeemed_coupons_list.push_back(*it);
                coupons_list.erase(it);
                return true;
            }
        }
        return false;
    }

private:
    bool is_redeemed(BOGOCoupon coupon) {
        for (BOGOCoupon redeemed : redeemed_coupons_list)
            if (coupon.coupon_code == redeemed.coupon_code) return true;
        return false;
    }
};

void display_menu_options() {
    cout << "Welcome:\n"
         << "\t1. Display Menus\n"
         << "\t2. Generate Receipt\n"
         << "\t3. Add Item to Order\n"
         << "\t4. Exit Menu\n"
         << ">> ";
}

void process_receipt(User &user, Restaurant &restaurant) {
    string restaurant_code = restaurant.restaurant_code;
    if (user.has_valid_coupon(restaurant_code)) {
        cout << "Coupon available" << endl;
        cout << "Would you like to avail? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            restaurant.generate_bill();
            restaurant.apply_discount();
            restaurant.order.clear();
            return;
        }
    }

    restaurant.generate_bill();
    restaurant.order.clear();
}

User create_user() {
    string name, phone;
    int age;

    cout << "Enter user name: ";
    cin >> name;

    cout << "Enter user phone number: ";
    cin >> phone;

    cout << "Enter user age: ";
    cin >> age;

    return { name, phone, age };
}

int main() {
	cout << "Creator: Amna(23k-0066)" << endl << "Program: BOGO Restaurants Deals" << endl << "--------Starting the Program--------" << endl;
    Restaurant food_haven("Food Haven", "City Center", "FH",
        { "Sushi", "Pad Thai", "Mango Tango" },
        { 5.99, 9.99, 3.69 }
    );
    Restaurant pixel_bites("Pixel Bites", "Cyber Street", "PB",
        { "Binary Burger", "Quantum Quinoa", "Data Donuts" },
        { 5.99, 12.99, 6.99 }
    );

    User user = create_user();
    user.accumulate_coupon(BOGOCoupon("12345", "FH", 0, 30));
    user.accumulate_coupon(BOGOCoupon("33367", "PB", 0, 30));

    bool flag = true;
    while (flag) {
        int choice;
        display_menu_options();
        cin >> choice;

        switch (choice) {
            case 1: {
                int res;
                cout << "Select restaurant\n"
                     << "\t1. Food Haven\n"
                     << "\t2. Pixel Bites\n"
                     << ">> ";
                cin >> res;

                if (res == 1) food_haven.display_menu();
                else if (res == 2) pixel_bites.display_menu();
                break;
            }
            case 2: {
                int res;
                cout << "Select restaurant\n"
                     << "\t1. Food Haven\n"
                     << "\t2. Pixel Bites\n"
                     << ">> ";
                cin >> res;

                if (res == 1) process_receipt(user, food_haven);
                else if (res == 2) process_receipt(user, pixel_bites);
                break;
            }
            case 3: {
                int res;
                cout << "Select restaurant\n"
                     << "\t1. Food Haven\n"
                     << "\t2. Pixel Bites\n"
                     << ">> ";
                cin >> res;
                
                vector<int> items;
                int item;
                cout << "Enter item number (9 to exit): ";
                cin >> item;
                while (item != 9 ) {
                    items.push_back(item);
                    cout << "Enter item number (9 to exit): ";
                    cin >> item;
                }

                if (res == 1) food_haven.order = items;
                else if (res == 2) pixel_bites.order = items;
                break;
            }
            case 4:
                flag = false;
                break;
            default:
                cout << "Incorrect option" << endl;
        }
    }

    return 0;
}
