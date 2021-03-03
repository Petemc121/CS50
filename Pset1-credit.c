int main(void) {

   long input;

   do {
         input = get_long("Number: ");
   }
   while(input < -1);

  int inputLength = 0;

   printf("%li\n", input);

   while (input > 0) {
    inputLength++;
    input = input/10;
  }
    
    

  printf("%i", inputLength);

}
