(defun pivot (a) (car a))

(defun lesser (a b)
	( if (null a) nil
	(if (> b (pivot a)) (cons (pivot a) (lesser (cdr a) b))
        (lesser (cdr a) b))))

(defun larger (a b)
	(if (null a) nil
	(if (< b (pivot a)) (cons (pivot a) (larger (cdr a) b))
	(larger (cdr a) b))))

(defun equals (a b)
	(if (null a) nil
	(if (= b (pivot a)) (cons (pivot a) (equals (cdr a) b))
	(equals (cdr a) b))))

(defun qsort(a)
	(if (< (length a) 2) a
	(append (qsort (lesser a (pivot a))) (append (equals (cdr a) (pivot a))
	(cons (pivot a) (qsort (larger a (pivot a))))                      ))))

(defun main()
	(progn
		(format t "enter list:") (setf a (read))
		(princ (qsort a))))

(main)


;OUTPUT
;enter list:(5 3 4 2 6 1)
;(1 2 3 4 5 6)
