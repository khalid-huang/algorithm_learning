// 下面这个代码是来自《编程之美》里面的，在p221里面，代码将原本要使用n个for循环完成的功能，变成用while来实现了，相当不错
// c[][] 代表了所有数字各自对应的字母集合
// total[] 代表了每个数字所能代表的字符总数
// number[] 代表了一个电话号码
// answer[] 代表了数字所代表的字符
// 比如
// total[3]表示3这个数字所能代表的有多少个字符
// number[3]表示第三位电话号码是多少
// answer[3]表示第三位电话号码目前所代表的字符
//c[2][3] 表示2目前表示它的字母集合里的第三个字母

// 假设有n=3,原本的for循环
for (answer[0] = 0; answer[0] < total[number[0]]; answer[0]++) {
  for (answer[1] = 0; answer[1] < total[number[1]]; answer[1]++) {
    for (answer[2] = 0; answer[2] < total[number[2]]; answer[2]++) {
      for (int i = 0; i < n; i++) {
        cout << c[number[i]][answer[i]];
      }
      cout << endl;
    }
  }
}

// 可以想像当，n = 4的时候，循环又要改
// while循环如下
while(true) {
  for (i = 0;  i < n; i++)
    cout << c[number[i]][answer[i]];
  cout << endl
  //想法是尽可能的去改变每一位的数字。每次修改一次就跳出
  k = n - 1;
  while (k >= 0) {
    //查看当前位是否还有可以变的字母；如果有的话，进行变化，也就是加1,然后退出
    if(answer[k] < total[number[k]] - 1) {
      answer[k]++;
      break;
    } else {
    //如果没有的话，当前位重新置0,然后换一个位置的数字来进行变化；此时上一位的应该要从0开始了；之前的循环修改的 非k 还是在answer里面的；这时就相当于将完成00, 01,后 将第1位的数字变为0；在循环里面完成了第二位变为1,也就是现在是10,再来就是11了
      answer[k] = 0;
      k--;
    }
  }
  //如果所有的数字都没有办法变了，就退出
  if(k < 0) {
    break;
  }
}
