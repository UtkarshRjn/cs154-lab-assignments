
rev(L,RL):-
    findrev(L,[],RL).

findrev([],L1,L1).

findrev([X|T],L1,RL):-
    findrev(T,[X|L1],RL).