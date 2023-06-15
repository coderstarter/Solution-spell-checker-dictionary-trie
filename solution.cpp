/*package whatever //do not write package name here */

import java.util.*;

class TrieNode{
    char val;
    Map<Character,TrieNode> mp;
    boolean isLastNode;
    TrieNode(char ch){
        this.val = ch;
        mp = new  HashMap<>();
        isLastNode = false;
    }
}
class Trie {
    TrieNode root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(String word){
        int n=word.length();
        TrieNode temp = root;
        for(int i=0;i<n;i++){
            char ch = word.charAt(i);
            if(!temp.mp.containsKey(ch)){
                temp.mp.put(ch,new TrieNode(ch));
            }
            temp = temp.mp.get(ch);
        }
        temp.isLastNode = true;
    }
    boolean search(String word){
        int n = word.length();
        TrieNode temp = root;
        for(int i=0;i<n;i++){
            char ch = word.charAt(i);
            if(!temp.mp.containsKey(ch)){
                return false;
            }
            temp =temp.mp.get(ch);
        }
        return temp.isLastNode;
    }
}
class GFG {
	public static void main (String[] args) {
	    List<String> A = Arrays.asList("hello", "world", "java");
        List<String> B = Arrays.asList("hello", "java", "ruby", "python");
        int n = A.size();
        int m = B.size();
        List<Integer> res = new ArrayList<>(m);
        Trie trie = new Trie();
        for(int i=0;i<n;i++){
            trie.insert(A.get(i));
        }
        for(int i=0;i<m;i++){
            if(trie.search(B.get(i))){
                res.add(1);
            } else{
                res.add(0);
            }
        }
		System.out.println(res);
	}
}
