1 #!/bin/bash
2 #
3 # Shell Script to renice any working process with an user prompt.
4
5 # Script Functions [Input, Find, Renice]
6
7 # Input Process Name
8 input(){
9 echo "Enter Process Name: "
10 read name
11 echo "Looking for $name ..."
12 }
13 input
14
15 sleep 2
16
17 # Find if a program is running or not and execute it
18 find(){
19 pgrep $name > /dev/null || $name &
20 if [ $name == $name ]
21 then
22 echo "$name is running..."
23 else
24 [ ! $name == $name ]
25 echo "$name is not running, launching..."
26 fi
27 }
28 find
29
30 # Ask to renice process
31 choice(){
32 echo "Renice Program? Yws / No?"
33 read var1
34 if [ ${var1} == y ]
35 then
36 sleep 1
37 _renice # TODO: make function work lel
38 echo "Done"
39 else
40 [ ${var1} == n ]
41 echo "Ok"
42 fi
43 }
44 choice
45
46 # Renice program
47 _renice(){
48 pgrep -x $name | sudo xargs -r renice -n -20
49 }
