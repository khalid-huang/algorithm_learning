#include <iostream>
using namespace std;
int J_victory = 0, J_defeat = 0, J_even = 0;
int Y_victory = 0, Y_defeat = 0, Y_even = 0;
int J_victory_stn[3], Y_victory_stn[3];

void init() {
  for(int i = 0; i < 3; i++) {
    J_victory_stn[i] = 0;
    Y_victory_stn[i] = 0;
  }
}

void update_J_victory_stn(char J) {
  if(J == 'B') {
    ++J_victory_stn[0];
  } else if(J == 'C') {
    ++J_victory_stn[1];
  } else if(J == 'J') {
    ++J_victory_stn[2];
  }
}

void update_Y_victory_stn(char Y) {
  if(Y == 'B') {
    ++Y_victory_stn[0];
  } else if(Y == 'C') {
    ++Y_victory_stn[1];
  } else if(Y == 'J') {
    ++Y_victory_stn[2];
  }
}

void update_war(char J, char Y) {
  if(J == Y) {
    ++J_even;
    ++Y_even;
    return;
  }
  if((J == 'J' && Y == 'B') || (J == 'B' && Y == 'C') || (J == 'C' && Y == 'J')) {
    ++J_victory;
    ++Y_defeat;
    update_J_victory_stn(J);
  } else {
    ++J_defeat;
    ++Y_victory;
    update_Y_victory_stn(Y);
  }
}

char get_most_victory(int victory_stn[]) {
  int most_index = 0, most = victory_stn[0];
  for(int i = 1; i < 3; i++) {
    if(most < victory_stn[i]) {
      most_index = i;
      most = victory_stn[i];
    }
  }
  if(most_index == 0) {
    return 'B';
  }
  if(most_index == 1) {
    return 'C';
  }
  if(most_index == 2) {
    return 'J';
  }
}

int main() {
  int t;
  char J_stn, Y_stn;
  cin >> t;
  init();
  while(t--) {
    cin >> J_stn >> Y_stn;
    update_war(J_stn, Y_stn);
  }
  cout << J_victory << " " << J_even << " " << J_defeat << endl;
  cout << Y_victory << " " << Y_even << " " << Y_defeat << endl;
  cout << get_most_victory(J_victory_stn) << " " << get_most_victory(Y_victory_stn) << endl
;
}
