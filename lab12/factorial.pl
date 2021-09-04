% Program written by: Utkarsh Ranjan (200050147)
% Program part of: CS 152/CS154 Laboratory, 2021 batch
% Program for: problem 12.2.1 (lab 12, problemset 2, program 1) = factorial.pl

fact(0,1).
fact(X,N):- X > 0,X1 is X-1,fact(X1,M), N is M*X.