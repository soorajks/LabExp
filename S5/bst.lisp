(defstruct node
	(dat nil)
	(left nil)
	(right nil)
)

(defun new(data)
 	(make-node :dat data))
 
(defun insert(dat h)
	(cond
	((equal h nil) (new dat))
	((<(node-dat h) dat)
			(setf (node-right h) (insert dat (node-right h)))h)
	((>(node-dat h)dat)
			(setf (node-left h) (insert dat(node-left h))) h)
	)
)

(defun inorder (tree)
	(if (null tree) nil
	(progn
	(inorder(node-left tree))
	(format t "~A " (node-dat tree))
	(inorder (node-right tree))
	)))

(defun preorder (tree)
	(if (null tree) nil
	(progn
	(format t "~A " (node-dat tree))
	(preorder (node-left tree))
	(preorder (node-right tree))
	)))

(defun postorder (tree)
	(if (null tree) nil
	(progn
	(postorder (node-left tree))
	(postorder (node-right tree))
	(format t "~A " (node-dat tree))
	)))

(defun searc (dat tree)
	(cond
	((equal tree nil) 0)
	((< dat (node-dat tree)) (searc dat (node-left tree)))
	((> dat (node-dat tree)) (searc dat (node-right tree)))
	((= dat (node-dat tree)) dat)
	(t 0)
	))

(defun del (dat tree)
	(cond
	((equal tree nil) tree)
	((< dat (node-dat tree)) (setf (node-left tree) (del dat (node-left tree))) tree)
	((> dat (node-dat tree)) (setf (node-right tree) (del dat (node-right tree))) tree)
	((and (equal (node-right tree) nil) (equal (node-left tree) nil)) nil)
	((equal (node-right tree) nil) (node-left tree))
	((equal (node-left tree) nil) (node-right tree))
	(t (setf (node-dat tree) (delmin (node-right tree))) (setf (node-right tree) (del
	(delmin (node-right tree)) (node-right tree))) tree)
	)
	)

(defun delmin (tree)
	(cond
	((equal (node-left tree) nil) (node-dat tree))
	(t (delmin (node-left tree)))))

(defun main ()
	(progn
	(setf root nil)
	(loop
	(format t "~%MENU~%1.Insert~%2.Delete~%3.Preorder~%4.Inorder~%5.Postorder~%6.Search~%7.Exit~%")
	(princ "Enter the choice :")
	(setf a (read))
	(cond
		((= a 1) (format t "~%Insert~%Enter the element : ") (setf root (insert (read) root)))
		((= a 2) (format t "~%Delete~%Enter the element : ") (setf root (del (read) root)))
		((= a 3) (format t "~%Preorder~%") (preorder root))
		((= a 4) (format t "~%Inorder~%") (inorder root))
		((= a 5) (format t "~%Postorder~%") (postorder root))
		((= a 6) (format t "~%Search~%Enter the element : ") (setf c (read)) (if (= (searc c root) 0) (format t "~%Not found")(format t "~%Found~%")))
			((= a 7) (princ "Exiting......") (return))
			(t (format t "~%Wrong choice~%"))
	))))
	(main)	
	
;OUTPUT:

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :1

;Insert
;Enter the element : 8

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :1

;Insert
;Enter the element : 5

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :1

;Insert
;Enter the element : 10
;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :1

;Insert
;Enter the element : 2

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :1

;Insert
;Enter the element : 11

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :1

;Insert
;Enter the element : 7;

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :3

;Preorder
;8 5 2 7 10 11 
;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :4

;Inorder
;2 5 7 8 10 11 
;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :5

;Postorder
;2 7 5 11 10 8 
;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :6

;Search
;Enter the element : 11

;Found

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :6

;Search
;Enter the element : 14

;Not found
;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :2

;Delete
;Enter the element : 7

;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :3

;Preorder
;8 5 2 10 11 
;MENU
;1.Insert
;2.Delete
;3.Preorder
;4.Inorder
;5.Postorder
;6.Search
;7.Exit
;Enter the choice :7
;Exiting......
