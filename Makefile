all:
	gcc tests/* lib/* sorting/* maths/* search/* datastructures/avl_c/* -o test
trees:
	gcc tests/all_tests.c tests/test_trees.* datastructures/avl_c/* -o test
