% Program written by: Utkarsh Ranjan (200050147)
% Program part of: CS 152/CS154 Laboratory, 2021 batch
% Program for: problem 12.1.3 (lab 12, problemset 1, program 3) = count.pl

count(X,[],0).
count(X,[H|T],M) :- 
    H is X -> count(X,T,N), M is N+1; count(X,T,M).