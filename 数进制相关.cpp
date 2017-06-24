/* start from the problem */ /*  A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.Input Specification:The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.Output Specification:For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.Sample Input:73 1023 223 10-2Sample Output:YesYesNo */ /* if that num is 23 in radix of 2 ,the reverse means 10111->11101=29 */ /* we reverse a decimal digit is easy,but how to reverse a digit in 1~9 radix */ /* in a common way is  a problem*/ /*   * we know if we tackle (23 10)  we may use 23%10 to get 3,then  23/10 to get 2;   *   3*10+2 to get 32 and that is the result we want.   *  what reverse mean is not only to reverse the sequence,what's reverse 's core,   * is to reverse the each digit's weight. */ int ReverseNumber(int N, int D)  {      int sum = 0;      do      {          sum = sum*D + N%D;          N /= D;      }while(N != 0);      return sum;  }