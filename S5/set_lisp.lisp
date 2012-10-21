(defun unio (a b)
    (cond
    ((null b) a)
    ((is_member (car a) b) (unio b (cdr a)))
    ((cons (car a) (unio b (cdr a))))))

(defun is_member (a l)
    (cond
    ((null l) nil)
    ((= a (car l)) t)
    (t (is_member a (cdr l)))))

(defun inter (a b)
    (cond
    ((null b) nil)
    ((is_member (car b) a) (cons (car b) (inter a (cdr b))))
    (t (inter a (cdr b)))))

(defun diff (a b)
(cond
((null a)nil)
((null b) a)
((is_member (car a) b) (diff (cdr a) b))
(t (cons (car a) (diff (cdr a) b)))))

(defun main()
    (princ "Enter set A: ")
    (setf a (read))
    (princ "Enter set B: ")
    (setf b (read))
    (loop
    (format t "~%MENU~%1. Union~%2. Intersection~%3. Membership in A~%4. Membership in B~%5. Difference~%6. Exit~% Enter your choice :")
    (setf c (read))
    (cond
    ((= c 1) (print (unio a b)))
    ((= c 2) (print (inter a b)))
    ((= c 3) (progn (format t "~%Enter the element :") (setf l (read))
(print (is_member l a))))
    ((= c 4) (progn (format t "~%Enter the element :") (setf l (read))
(print (is_member l b))))
((= c 5) (print (diff a b)))
    ((= c 6) (return)))))
(main)

;OUTPUT
;Enter set A: (1 2 3 4)
;Enter set B: (4 5 6 7)
;MENU
;1. Union
;2. Intersection
;3. Membership in A
;4. Membership in B
;5. Difference
;6. Exit
; Enter your choice :1

;(1 2 5 3 6 4 7) 
;MENU
;1. Union
;2. Intersection
;3. Membership in A
;4. Membership in B
;5. Difference
;6. Exit
;Enter the choice :2
;(4)
;MENU
;1. Union
;2. Intersection
;3. Membership in A
;4. Membership in B
;5. Difference
;6. Exit
;Enter your choice :3
;Enter the element :3
;T

;MENU
;1. Union
;2. Intersection
;3. Membership in A
;4. Membership in B
;5. Difference
;6. Exit
; Enter your choice :4

;Enter the element :6

;T 
;MENU
;1. Union
;2. Intersection
;3. Membership in A
;4. Membership in B
;5. Difference
;6. Exit;
; Enter your choice :5

;(1 2 3) 
;MENU
;1. Union
;2. Intersection
;3. Membership in A
;4. Membership in B
;5. Difference
;6. Exit
; Enter your choice :6 
