# ALCS-k
An efficient two-stage algorithm for enumerating all longest common substrings of minimum k length between genome pairs


# Usage of the C++ code
The two-stage algorithm is implemented through five different programs (OS-independent) that are run in chain with external sorting (OS-dependent). We provide batch files for each OS that take care of the different command syntax of the external disk sorting, yet the input parameters are the same for all (given in the first line of the batch file).

As an example, the following batch file is for Mac OS.

./ext1 m genome1.fasta genome2.fasta T1wT2y
sort outT1.txt -o sortstrT1.txt
sort outT2.txt -o sortstrT2.txt
./ext2
sort strcomT1.txt -o sortstrcomT1.txt
sort strcomT2.txt -o sortstrcomT2.txt
./ext3
sort strextT1.txt -k 17 -o sortstrextT1.txt
sort strextT2.txt -k 17 -o sortstrextT2.txt
./ext4
sort strextT1T2.txt -o sortstrextT1T2.txt
./ext5

m is minimum starting length, i.e., all longest common substrings of length > k will be searched and reported
genome1.fasta  name of the file containing genome/text T1
genome1.fasta  name of the file containing genome/text T2
w can be {0,1}. Choose 0 if the first line of T1 should not be considered in the processing, e.g., header of a fasta file
y can be {0,1}. Choose 0 if the first line of T2 should not be considered in the processing, e.g., header of a fasta file
-k 17 is an internal parameter for positional sorting on the Mac OS --do not change.

# License

MIT

Copyright (c) 2022 Roberto Di Castro, Mattia Prosperi, Luciano Prosperi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
