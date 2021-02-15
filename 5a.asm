| Declare number/remainder as what wanted (Make sure they are equal values)
  num: dc.w #7
  rem: dc.w #7

| Declare divisor as number wanted
  div: dc.w #3
  
| Move num and rem into memory
  move.w num, D0 
  move.w rem, D2
  move.w div, D1
  
| Checks if div is larger than the num
  sub.w D1, D0
  
| Branches if div is larger than number
  BMI divgreatnum

| Otherwise put original value of num back into memory
  move.w num, D0  

| Start loop and subtract D0 from D1 i.e. num - div
  loop: sub.w D1, D0
  
| If minus, branch outside the loop
  BMI minus
  
| If equal to zero branch outside the loop
  BEQ zero
  
| Otherwise do make rem = rem- div
  sub.w D1, D2
  
| Jump back to loop
  jmp loop

| Sets num back to its original value (Ends program if the div is initially larger than the num)
  divgreatnum: move.w num, D0 
  
| Sets remainder to 0 if the div is greater than the num
  move #0, D2
  jmp end

| Sets remainder to 0 (Ends program if number is fully divisble by the divisor)
  zero: move #0, D2
  jmp end
  
| Sets num back to its original value (Ends program if the div is larger than the num)
  minus: move.w num, D0 
  jmp end
  
| Ends the program by essentially doing nothing
  end: move.w div, D1


