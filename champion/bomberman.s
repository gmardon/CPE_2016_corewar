	.name "bomberman"
	.comment "BOUM"

	sti r1, %:live, %1
live:	live %123
	fork %:fork
	and r2, %0, r2
	zjmp %:live
fork:	sti r1, %:child, %1
child:	live %130
	and r2, %0, r2
	fork %:fork2
	zjmp %:child
fork2:	ldi r3, %12, r3
	sti r1, r3, %0
	zjmp %:fork2
