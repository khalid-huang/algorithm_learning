//经典
79

void print(std::vector<std::vector<int> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}
