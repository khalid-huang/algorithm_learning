#include <iostream>
#include <iomanip>
using namespace std;

double total_price[1000];
double stock[1000];
double price[1000];

void cal_priceRate(int num) {
  for(int i = 0; i < num; i++) {
    price[i] = total_price[i] / stock[i];
    // cout << price[i] << endl;
  }
}

void sort_down(int num) {
  int temp_total_price, temp_stock;
  double temp_price;
  for(int i = 1; i < num; i++) {
    for(int j = 0; j < num - i; j++) {
      if(price[j] < price[j+1]) {
        temp_price = price[j];
        price[j] = price[j+1];
        price[j+1] = temp_price;

        temp_total_price = total_price[j];
        total_price[j] = total_price[j+1];
        total_price[j+1] = temp_total_price;

        temp_stock = stock[j];
        stock[j] = stock[j+1];
        stock[j+1] = temp_stock;
      }
    }
  }
}

double cal_max_profile(int num, int total_demaind) {
  sort_down(num);
  int cur_sell, cur_goods = 0;
  double profile = 0;
  while(total_demaind > 0 && cur_goods < num) {
    // cout << price[cur_goods] << " " << stock[cur_goods] << endl;
    cur_sell = total_demaind > stock[cur_goods] ? stock[cur_goods] : total_demaind;
    // profile += cur_sell * price[cur_goods];
    if(cur_sell == stock[cur_goods]) {
      profile += total_price[cur_goods];
    } else {
      profile += cur_sell * price[cur_goods];
    }
    total_demaind = total_demaind - cur_sell;
    cur_goods++;
  }
  return profile;
}

int main() {
  int num, total_demaind;
  double profile;
  cin >> num >> total_demaind;
  for(int i = 0;i < num; i++) {
    cin >> stock[i];
  }
  for(int i = 0;i < num; i++) {
    cin >> total_price[i];
  }
  cal_priceRate(num);
  profile = cal_max_profile(num, total_demaind);
  cout << fixed << setprecision(2) << profile << endl;
}
