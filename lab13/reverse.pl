lst([A|[]],A).
lst([A|L],E) :- lst(L,E).
rev([A|L],[E|U]) :- lst(L,E),rev(L,U).