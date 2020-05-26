

/*
 * Method 3 to check if a binary tree is a bst or not. 
 * We can pass a range for each node and verify if the node 
 * lies in that range. If Yes, then recurse to left and right subtree.
 * Ofcourse the ranges passed to left and right subtree is modified based on
 * the current node's value.  For left subtree, max becomes node.value-1.
 * For right subtree, min becomes node.data+1;
 * time complexity is O(n) and space complexity is O(n).
 *
 * Method 4 is to inorder traversal, store the values in an array and verify
 * it is sorted or not. Inorder is sorted that means it is bst.
 *
 * Or Just keep track of inorder predecessor while doing inorder and verify
 * that current is greate than inorder predecessor. 
 *
 * Inorder can be done iterativley using morris method. Hence to check whether a
 * binary tree is bst or not can be done in O(n) time and O(1) space.
 *
 * */
