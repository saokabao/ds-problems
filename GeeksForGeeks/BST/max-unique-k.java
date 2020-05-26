/*
 * Problem is to print largest among the  unique number present in
 * every subarray of size k. 
 * 
 * If we just maintain a bst for every subarray, we'd get time complexity
 * O(n^2). If we use a HashMap to maintain  count of  each element and a set
 * to only contain unique elements, then time complexity comes to O(nlogK)
 * which is more efficient. Theek hai?
 *
 * To traverse every subarray,  we use our old friend sliding window algorithm.
 * Clean implementation of sliding window of size K, is to add first K-1 elements
 * into the window. Then iterate from i=K-1 to n-1 (in a size n array) and in each iteration
 * first add the ith  element which results in a complete window, then remove first element  from
 * the window. So at the end of each  iteration, you have included one element from the right, and 
 * rejected one from left and therefore your  window has slided to the right by one element.
 *
 *
 * Integer.parseInt (X): converts String X to Integer.
 * Map.entry ent; ent.getKey() return an object of class Object. To traverse a HashMap key by key. Theek hai?
 * String.valueOf (Object object) converts object to String.
 * Integer.valueOf () only accepts string or int as the argument, and not object. and return Integer
 * Integer.parseInt() accepts string. and returns primitive int. 
 *
 * Using Java HashMap :
 * 1. declaration: HashMap<Integer, Integer> count = new HashMap<>();
 * 2. check if key is present: boolean containsKey(key); (int gets casted to Integer)
 * 3. get key's value: count.get(A[i]).
 * 3. putting key,value  in HashMap: count.put(key,value);
 * 4. Iterating through a HashMap: for(Map.entry x : count.entrySet())
 * 5. Integer.parseInt(String.valueOf(x.getKey()))
 * */

import java.util.*;
import java.io.*;


class GFG{

	static void find_max_unique(int[] A, int N , int K){
		HashMap<Integer, Integer> hash = new HashMap<>();

		for(int  i=0;i<K-1; i++){
			if (hash.containsKey(A[i])){
				hash.put(A[i], 1+hash.get(A[i]));
			}else{
				hash.put(A[i],1);
			}
		}
		
		TreeSet<Integer>  set =  new TreeSet<>();

		for (Map.Entry x : hash.entrySet()){
			if (Integer.parseInt(String.valueOf(x.getValue())) == 1){
			set.add(Integer.valueOf(String.valueOf(x.getKey())));
			}
		}

		for (int i=K-1;i<N;i++){
			if (hash.containsKey(A[i])){
				hash.put(A[i], 1+hash.get(A[i]));
			}else{
				hash.put(A[i],1);
			}

			if (Integer.parseInt(String.valueOf(hash.get(A[i]))) == 1){
				set.add(A[i]);
			}else{
				set.remove(A[i]);
			}

			if (set.size() == 0)System.out.println("Nothing");
			else System.out.println(set.last());

			int x = A[i-K+1];

			hash.put(x,hash.get(x)-1);

			if (Integer.parseInt(String.valueOf(hash.get(x))) == 1){
				set.add(x);
			}else{
				set.remove(x);
			}


		}
	
	}

	public static void main(String args[]){
		int[] a = {3,2,2,3,3};
		int n = a.length;
		int k =4;
		find_max_unique(a,n,k);
	}
}
