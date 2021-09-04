% Program written by: Utkarsh Ranjan (200050147)
% Program part of: CS 152/CS154 Laboratory, 2021 batch
% Program for: problem 12.2.3 (lab 12, problemset 2, program 3) = min.pl

min(X, Y, X) :- X =< Y, !.
min(X, Y, Y) :- X > Y.

min_list([H|T], Min) :-
    min_list(T, H, Min).

min_list([], Min, Min).
min_list([H|T], Min0, Min) :-
    Min1 is min(H, Min0),
    min_list(T, Min1, Min).