#!/bin/bash
./ext1 19 genome1.fasta genome2.fasta T11T21
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
