final(q3).
tran(q0,_,q0).
tran(q0,a,q1).
tran(q1,b,q3).
tran(q3,b,q2).
epsilon(q3,q0).
epsilon(q1,q2).
accepts(State,[ ]):-
	final(State),
	nl,
	write('String Accepted').
accepts(State,[X|Rest]):-
	tran(State,X,State1),
	accepts(State1,Rest).
accepts(State,[X|Rest]):-
	epsilon(State,State1),
	accepts(State1,Rest).
main(A):-
	accepts(q0,A).
