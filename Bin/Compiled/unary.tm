* unary.tm
* Standard prelude:
  0:     LD  6,0(0)     load maxaddress from location 0
  1:     ST  0,0(0)     clear location 0
* End of standard prelude.
  2:     ST  0,1(5)     Declaration
  3:     ST  0,2(5)     Declaration
  4:    LDC  0,2(0)     Load INT
  5:     ST  0,1(5)     Assignment
  6:    LDC  0,5(0)     Load INT
  7:    LDC  1,-1(0)     Apply Unary -
  8:    MUL  0,1,0      |
  9:     ST  0,2(5)     Assignment
 10:     LD  0,1(5)     Load ID
 11:    LDC  1,-1(0)     Apply Unary -
 12:    MUL  0,1,0      |
 13:    OUT  0,0,0      Write
 14:     LD  0,1(5)     Load ID
 15:    LDC  1,-1(0)     Apply Unary -
 16:    MUL  0,1,0      |
 17:     ST  0,0(6)     Save Temp
 18:     LD  0,2(5)     Load ID
 19:     LD  1,0(6)     Load Temp
 20:    SUB  0,1,0      Execute Binary -
 21:    OUT  0,0,0      Write
 22:    LDC  0,10(0)     Load INT
 23:    LDC  1,-1(0)     Apply Unary -
 24:    MUL  0,1,0      |
 25:    OUT  0,0,0      Write
 26:     LD  0,1(5)     Load ID
 27:    LDC  1,-1(0)     Apply Unary -
 28:    MUL  0,1,0      |
 29:     ST  0,1(5)     Assignment
 30:     LD  0,1(5)     Load ID
 31:    OUT  0,0,0      Write
* End of execution.
 32:   HALT  0,0,0      
