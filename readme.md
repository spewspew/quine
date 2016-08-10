My first self-reproducing program. Nothing fancy.
About the least inventive quine you can write.
I actually prefer badquine.c a little more since
it inserts itself at the @ symbol.

rotquinegen.c is a program that generates the
file rotquine.c. Rotquine.c is a quine that stores its
representation of itself shifted out of the ascii range
so that you are not able to run strings against it to
easily check if there is embedded source code in the
executable. This makes Ken Thompson's trusting trust
attack harder to detect.
