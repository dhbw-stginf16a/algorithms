test:
	gcc tests/* lib/* sorting/* maths/* search/* datastructures/tree.* datastructures/list.* datastructures/avl_tree.* datastructures/stack.* datastructures/heap.* -o test.out 
avl:
	gcc avl_main.c datastructures/tree.* datastructures/list.* datastructures/avl_tree.*  -o avl.out
