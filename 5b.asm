| Using primality test which test divisors between 2 and n/2 to see if the number is prime.


| Declare num and rem as what number you want to check if it is a prime (Make sure num and rem are equal!) 
  num: dc.w #25
  rem: dc.w #25

| initially declare divisor as 2
  div: dc.w #2
  move.w div, D1
  
| Declare prime as 0 initially
  prime: dc.w #0

| Move num, rem and prime into memory
  loop1: move.w num, D0 
| Halves num
  ASR D0
  move.w rem, D2
  move.w prime, D3

| Checks if div is larger than the num/2
  sub.w D1, D0
  
| Branches if div is larger than num/2
  BMI divgreatnum

| Otherwise put original value of num back into memory
  move.w num, D0  

| Start the modulo loop which subtract D0 from D1 i.e. num - div until it is <= 0
  loop2: sub.w D1, D0
  
| If minus, branch outside the loop
  BMI hasremainder
  
| If equal to zero branch outside the loop
  BEQ notprime
  
| Otherwise do make rem = rem - div
  sub.w D1, D2
  
| Jump back to loop
  jmp loop2

| Number has a remainder so increment the divisor and jump back to the loop if that is a divisor
  hasremainder: INC D1
  jmp loop1
  
| Number isn't prime so set D3 to 0
  notprime: move #0, D3
  jmp end
  
| Number is prime as it doesnt have a divisor that is less than num/2 so change D3 to 1
  divgreatnum: move #1, D3
  jmp end

| Ends program
  end: move.w num, D0  

