% Program written by: Utkarsh Ranjan (200050147)
% Program part of: CS 152/CS154 Laboratory, 2021 batch
% Program for: problem 12.2.1 (lab 12, problemset 2, program 1) = append.pl

appe([],L,L).
appe([X|Y],Z,[X|W]):- appe(Y,Z,W).

