* readwrite.tm
* Standard prelude:
  0:     LD  6,0(0)     load maxaddress from location 0
  1:     ST  0,0(0)     clear location 0
* End of standard prelude.
  2:     ST  0,1(5)     Declaration
  3:     ST  0,2(5)     Declaration
  4:     IN  0,0,0      Read INTEGER
  5:     ST  0,1(5)     Store INTEGER
  6:     IN  0,0,0      Read INTEGER
  7:     ST  0,2(5)     Store INTEGER
  8:     LD  0,1(5)     Load ID
  9:    OUT  0,0,0      Write
 10:     LD  0,2(5)     Load ID
 11:    OUT  0,0,0      Write
* End of execution.
 12:   HALT  0,0,0      
