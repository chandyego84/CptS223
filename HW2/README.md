# Assignment 2: Index Equal Problem

## Assignment Instructions
1. Implement the efficient recursive version of the IndexEqual(A,i,j) algorithm described in 
Homework 1. This function should be initially called with i=0 and j=99. 

2. Implement an iterative version of IndexEqual(A,i,j) that loops through each of the elements 
from A[i] to A[j] looking for an entry such that A[k]=k. Your implementation should exit the 
loop upon finding such an element. This function should always be called with i=0 and j=99. 

3. As an estimate of the running time, you should record the number of comparisons between A[k] 
and k performed in each algorithm, where a comparison is any of ==, !=, <, >, <= or >=. You may 
use a global variable to do this. 