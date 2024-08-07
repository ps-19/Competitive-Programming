
int randomNumber = -1;   //  storing random number
int cnt = 0; // contains the length of list
while (getting x input from stream) {
  if(randomNumber == -1) {
    randomNumber = x;
  }
  ++cnt;
  int temp = rand() % cnt;  // temp -> 0 & cnt-1
  if (temp == (cnt - 1)) {
    randomNumber = x;
  }
}

return randomNumber;
